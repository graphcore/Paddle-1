/* Copyright (c) 2021 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#pragma once

#include <popart/sessionoptions.hpp>

namespace paddle {
namespace framework {
namespace ipu {

using VirtualGraphMode = popart::VirtualGraphMode;

struct IpuStrategy {
  int num_ipus = 1;
  int batches_per_step = 1;
  int batch_size = 1;
  bool is_training = true;
  bool save_init_onnx = false;
  bool save_last_onnx = false;
  int save_per_n_step = 1;
  popart::SessionOptions popart_options;
  bool need_avg_shard = false;
  bool enable_fp16 = false;
};

}  // namespace ipu
}  // namespace framework
}  // namespace paddle
