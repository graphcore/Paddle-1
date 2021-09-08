//   Copyright (c) 2021 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#include <memory>
#include <vector>

#include "paddle/fluid/framework/op_registry.h"
#ifdef PADDLE_WITH_IPU
#include "paddle/fluid/framework/ipu/ipu_backend.h"
#include "paddle/fluid/framework/tensor.h"
#endif

namespace paddle {
namespace operators {

template <typename T>
class IpuRuntimeKernel : public framework::OpKernel<T> {
 public:
  void Compute(const framework::ExecutionContext& ctx) const override {
#ifdef PADDLE_WITH_IPU
    auto ipu_backend = framework::ipu::IpuBackend::GetInstance();
    if (!ipu_backend->DeviceIsAttached()) {
      const platform::IPUDeviceContext& ipu_ctx =
          reinterpret_cast<const platform::IPUDeviceContext&>(
              ctx.device_context());
      ipu_backend->AttachDevice(ipu_ctx.DeviceId());
    }
    VLOG(4) << "IpuRuntime Kernel, begin to run graph";
    auto inputs = ctx.MultiInput<framework::Tensor>("FeedList");
    auto outputs = ctx.MultiOutput<framework::Tensor>("FetchList");
    auto output_names = ctx.OutputNames("FetchList");
    for (size_t i = 0; i < outputs.size(); ++i) {
      auto* out = outputs[i];
      auto oshape = ipu_backend->GetExecutor().GetOutputShape(output_names[i]);
      out->Resize(framework::make_ddim(oshape));
      // TODO(alleng) support muti-output dtypes
      // maybe get dtype from ipu_backend
      out->mutable_data<T>(ctx.GetPlace());
    }
    ipu_backend->Run(inputs, outputs);
#else
    PADDLE_THROW(platform::errors::PreconditionNotMet(
        "Please compile WITH_IPU option to enable ipu_runtime op"));
#endif
  }
};

}  // namespace operators
}  // namespace paddle
