#  Copyright (c) 2021 PaddlePaddle Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from __future__ import print_function

import numpy as np
import unittest
import sys
import paddle
import paddle.fluid as fluid
import paddle.fluid.compiler as compiler

paddle.enable_static()
SEED = 2021


@unittest.skipIf(not paddle.is_compiled_with_ipu(),
                 "core is not compiled with IPU")
class TestPoolNet(unittest.TestCase):
    def _test(self, run_ipu=True):
        main_prog = paddle.static.Program()
        startup_prog = paddle.static.Program()
        main_prog.random_seed = SEED
        startup_prog.random_seed = SEED
        np.random.seed(SEED)

        np_image = np.random.rand(1, 3, 10, 10).astype(np.float32)
        with paddle.static.program_guard(main_prog, startup_prog):
            image = paddle.static.data(
                name='image', shape=[1, 3, 10, 10], dtype='float32')
            conv1 = paddle.static.nn.conv2d(
                image, num_filters=3, filter_size=3, bias_attr=False)
            # bn = paddle.fluid.layers.batch_norm(image)
            max_pool2d_dg = paddle.nn.layer.MaxPool2D(
                kernel_size=2, stride=2, padding=1, ceil_mode=False)
            avg_pool2d_dg = paddle.nn.layer.AvgPool2D(
                kernel_size=2, stride=2, padding=1, ceil_mode=False)
            maxpool = max_pool2d_dg(conv1)
            result = avg_pool2d_dg(maxpool)

            loss = paddle.mean(result)

            adam = paddle.optimizer.Adam(learning_rate=1e-2)
            adam.minimize(loss)
        print(main_prog._to_readable_code())

        if run_ipu:
            place = paddle.IPUPlace()
        else:
            place = paddle.CPUPlace()
        exe = paddle.static.Executor(place)
        exe.run(startup_prog)

        if run_ipu:
            feed_list = [image.name]
            fetch_list = [loss.name]
            ipu_strategy = compiler.get_ipu_strategy()
            ipu_strategy.is_training = True
            program = compiler.IpuCompiler(
                main_prog, ipu_strategy=ipu_strategy).compile(feed_list,
                                                              fetch_list)
        else:
            program = main_prog

        result = []
        for epoch in range(100):
            loss_res = exe.run(program,
                               feed={"image": np_image},
                               fetch_list=[loss])
            result.append(loss_res)
        return np.array(result)

    def test_training(self):
        # cpu and ipu dimenstion mismatch, cpu:(100, 1, 1), ipu:(100, 1)
        cpu_loss = self._test(False).flatten()
        ipu_loss = self._test(True).flatten()
        self.assertTrue(np.allclose(ipu_loss, cpu_loss, atol=1e-4))


if __name__ == "__main__":
    unittest.main()
