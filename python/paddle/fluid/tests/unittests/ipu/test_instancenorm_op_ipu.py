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

import unittest

import numpy as np
import paddle
import paddle.static
from paddle.fluid.tests.unittests.ipu.op_test_ipu import IPUOpTest, ExecutionMode


@unittest.skipIf(not paddle.is_compiled_with_ipu(),
                 "core is not compiled with IPU")
class TestBase(IPUOpTest):
    def setUp(self):
        self.set_atol()
        self.set_training()
        self.set_data_feed()
        self.set_feed_attr()
        self.set_op_attrs()

    @property
    def fp16_enabled(self):
        return True

    def set_atol(self):
        self.atol = 1e-6
        self.rtol = 1e-5
        self.atol_fp16 = 1e-2
        self.rtol_fp16 = 1e-3

    def set_data_feed(self):
        x = np.random.uniform(size=[1, 3, 10, 10])
        self.feed_fp32 = {"x": x.astype(np.float32)}
        self.feed_fp16 = {"x": x.astype(np.float16)}

    def set_feed_attr(self):
        self.feed_shape = [x.shape for x in self.feed_fp32.values()]
        self.feed_list = list(self.feed_fp32.keys())

    def set_op_attrs(self):
        self.attrs = {"epsilon": 1e-05}

    def _test_base(self, exec_mode):
        scope = paddle.fluid.core.Scope()
        main_prog = paddle.static.Program()
        startup_prog = paddle.static.Program()
        main_prog.random_seed = self.SEED
        startup_prog.random_seed = self.SEED

        with paddle.fluid.scope_guard(scope):
            with paddle.static.program_guard(main_prog, startup_prog):
                x = paddle.static.data(
                    name=self.feed_list[0],
                    shape=self.feed_shape[0],
                    dtype='float32')

                with paddle.static.amp.fp16_guard():
                    if self.is_training:
                        ch = self.feed_shape[0][1]
                        conv1 = paddle.static.nn.conv2d(
                            x, num_filters=ch, filter_size=3, bias_attr=False)
                        scale = paddle.ParamAttr(trainable=True)
                        bias = paddle.ParamAttr(trainable=True)
                        out = paddle.fluid.layers.nn.instance_norm(
                            conv1,
                            param_attr=scale,
                            bias_attr=bias,
                            **self.attrs)
                        loss = paddle.mean(out)
                        adam = paddle.optimizer.Adam(learning_rate=1e-2)
                        adam.minimize(loss)
                    else:
                        out = paddle.fluid.layers.nn.instance_norm(
                            x, param_attr=True, bias_attr=True, **self.attrs)

                if self.is_training:
                    fetch_list = [loss.name]
                else:
                    fetch_list = [out.name]

            if exec_mode == ExecutionMode.CPU_FP32:
                place = paddle.CPUPlace()
            else:
                place = paddle.IPUPlace()

            exe = paddle.static.Executor(place)
            exe.run(startup_prog)

            if exec_mode != ExecutionMode.CPU_FP32:
                feed_list = self.feed_list
                ipu_strategy = paddle.static.IpuStrategy()
                ipu_strategy.set_graph_config(is_training=self.is_training)
                if exec_mode == ExecutionMode.IPU_POPART_FP16:
                    ipu_strategy.set_precision_config(enable_fp16=True)
                program = paddle.static.IpuCompiledProgram(
                    main_prog,
                    ipu_strategy=ipu_strategy).compile(feed_list, fetch_list)
            else:
                program = main_prog

            feed = self.feed_fp32
            if exec_mode > ExecutionMode.IPU_FP32:
                feed = self.feed_fp16

            if self.is_training:
                result = []
                for _ in range(self.epoch):
                    loss_res = exe.run(program,
                                       feed=feed,
                                       fetch_list=fetch_list)
                    result.append(loss_res)
                return np.array(result)
            else:
                result = exe.run(program, feed=feed, fetch_list=fetch_list)
                return result[0]

    def test(self):
        output_dict = {}
        for mode in ExecutionMode:
            if mode > ExecutionMode.IPU_FP32 and not self.fp16_enabled:
                break
            if mode > ExecutionMode.IPU_FP32 and self.is_training:
                break
            output_dict[mode] = self._test_base(mode).flatten()

        self.check(output_dict)


class TestTrainCase1(TestBase):
    def set_training(self):
        self.is_training = True
        self.epoch = 10


if __name__ == "__main__":
    unittest.main()
