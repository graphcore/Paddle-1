// Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.
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

#include <functional>
#include <memory>
#include "paddle/phi/api/include/tensor.h"
#include "paddle/phi/backends/cpu/forwards.h"

#if defined(PADDLE_WITH_CUDA) || defined(PADDLE_WITH_HIP)
#include "paddle/fluid/platform/device/gpu/gpu_types.h"
#include "paddle/phi/backends/gpu/forwards.h"
#include "paddle/phi/backends/gpu/gpu_decls.h"
#include "paddle/phi/backends/gpu/gpu_resources.h"
#endif

namespace paddle {
namespace internal {
class EigenGpuStreamDevice;
}  // namespace internal

class ResourceManager {
 public:
  explicit ResourceManager(const phi::Place& place, void* stream);
  ~ResourceManager();

 public:
  Eigen::DefaultDevice* GetCpuEigenDevice();

 private:
  void InitCPUResource();

 private:
  phi::Place place_;
  std::unique_ptr<Eigen::DefaultDevice> cpu_eigen_device_;

#if defined(PADDLE_WITH_CUDA) || defined(PADDLE_WITH_HIP)

 public:
  gpuStream_t GetStream() const;
  dnnHandle_t GetDnnHandle() const;
  blasHandle_t GetBlasHandle() const;
  blasHandle_t GetBlasTensorCoreHandle() const;
  blasHandle_t GetBlasTF32Handle() const;
  blasLtHandle_t GetBlasLtHandle() const;
  phi::solverHandle_t GetSolverDnHandle() const;
  phi::sparseHandle_t GetSparseHandle() const;
  Eigen::GpuDevice* GetGpuEigenDevice() const;
  int GetGpuComputeCapability() const;
  int GetGpuRuntimeVersion() const;
  int GetGpuDriverVersion() const;
  int GetGPUMultiProcessors() const;
  int GetGpuMaxThreadsPerMp() const;
  int GetGpuMaxThreadsPerBlock() const;
  std::array<int, 3> GetGpuMaxGridDimSize() const;

 private:
  void InitGPUResource(void* stream);
  void DestroyGPUResource();
  void InitGpuProperties();
  void InitGpuEigenDevice();
  void InitDnnHanlde();
  void DestroyDnnHandle();
  void InitBlasHandle();
  void DestroyBlasHandle();
  void InitBlasLtHandle();
  void DestroyBlasLtHandle();
  void InitSolverHandle();
  void DestroySolverHandle();
  void InitSparseHandle();
  void DestroySparseHandle();

 private:
  int compute_capability_;
  int runtime_version_;
  int driver_version_;
  int multi_process_;
  int max_threads_per_mp_;
  int max_threads_per_block_;
  std::array<int, 3> max_grid_dim_size_;

  bool owned_stream_{true};
  gpuStream_t stream_;
  std::unique_ptr<Eigen::GpuDevice> gpu_eigen_device_;
  std::unique_ptr<internal::EigenGpuStreamDevice> eigen_stream_;

  blasHandle_t blas_handle_{nullptr};
  blasHandle_t blas_tensor_core_handle_{nullptr};
  blasHandle_t blas_tf32_tensor_core_handle_{nullptr};
  blasLtHandle_t blaslt_handle_{nullptr};
  dnnHandle_t dnn_handle_{nullptr};
  phi::solverHandle_t solver_handle_{nullptr};
  phi::sparseHandle_t sparse_handle_{nullptr};
// DnnWorkspaceHandle
#endif
};

}  // namespace paddle
