// Copyright (c) 2021 PaddlePaddle Authors. All Rights Reserved.
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

#include "paddle/fluid/framework/ipu/popart_canonicalization/canonicalization_utils.h"
#include "paddle/fluid/framework/ipu/popart_canonicalization/op_builder.h"
#include "paddle/fluid/platform/enforce.h"

namespace paddle {
namespace framework {
namespace ipu {
namespace {

ir::Node *activation_op_handler(ir::Graph *graph, ir::Node *node,
                                const std::string &type) {
  auto new_node =
      CreateBaseOp(graph, node, type, {GetInputNode("X", node)}, node->outputs);
  return new_node;
}

ir::Node *relu_handler(ir::Graph *graph, ir::Node *node) {
  return activation_op_handler(graph, node, "popart_relu");
}

ir::Node *tanh_handler(ir::Graph *graph, ir::Node *node) {
  return activation_op_handler(graph, node, "popart_tanh");
}

ir::Node *log_handler(ir::Graph *graph, ir::Node *node) {
  return activation_op_handler(graph, node, "popart_log");
}

ir::Node *sigmoid_handler(ir::Graph *graph, ir::Node *node) {
  return activation_op_handler(graph, node, "popart_sigmoid");
}

ir::Node *sqrt_handler(ir::Graph *graph, ir::Node *node) {
  return activation_op_handler(graph, node, "popart_sqrt");
}

ir::Node *gelu_handler(ir::Graph *graph, ir::Node *node) {
  return activation_op_handler(graph, node, "popart_gelu");
}

ir::Node *log_softmax_handler(ir::Graph *graph, ir::Node *node) {
  auto axis_ = BOOST_GET_CONST(int, node->Op()->GetAttr("axis"));
  return CreateBaseOp(graph, node, "popart_logsoftmax", node->inputs,
                      node->outputs, {{"axis", int64_t{axis_}}});
}

REGISTER_HANDLER(relu, relu_handler);
REGISTER_HANDLER(tanh, tanh_handler);
REGISTER_HANDLER(log, log_handler);
REGISTER_HANDLER(sigmoid, sigmoid_handler);
REGISTER_HANDLER(sqrt, sqrt_handler);
REGISTER_HANDLER(gelu, gelu_handler);
REGISTER_HANDLER(log_softmax, log_softmax_handler);

}  // namespace
}  // namespace ipu
}  // namespace framework
}  // namespace paddle
