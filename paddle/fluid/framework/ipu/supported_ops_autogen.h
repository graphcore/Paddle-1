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

// TODO(alleng) add `//clang-format off` in python
// clang-format off
// Ops from AiGraphcoreOpset1
OP_DECL(popart_gelu,aiOnnxOpset1.gelu, NONE)
// OP_DECL(popart_groupnormalization, aiOnnxOpset1.groupnormalization, ARG(INT,num_groups) ARG(FLOAT,epsilon))
//
OP_DECL(popart_reshape,aiOnnxOpset.reshape, NONE)
// Ops from AiOnnxOpset10
OP_DECL(popart_averagepool, aiOnnxOpset.averagepool, ARG(INT_VEC,kernel_shape) ARG(INT,ceil_mode) ARG(INT,count_include_pad) ARG(INT_VEC,pads) ARG(INT_VEC,strides) )
OP_DECL(popart_convinteger, aiOnnxOpset.convinteger, ARG(INT_VEC,dilations) ARG(INT,group) ARG(INT_VEC,kernel_shape) ARG(INT_VEC,pads) ARG(INT_VEC,strides) )
OP_DECL(popart_dequantizelinear, aiOnnxOpset.dequantizelinear, NONE)
OP_DECL(popart_dropout, aiOnnxOpset.dropout, ARG(INT,num_outputs) ARG(FLOAT,ratio) )
OP_DECL(popart_isinf, aiOnnxOpset.isinf, ARG(INT,detect_negative) ARG(INT,detect_positive) )
OP_DECL(popart_matmulinteger, aiOnnxOpset.matmulinteger, NONE)
OP_DECL(popart_maxpool, aiOnnxOpset.maxpool, ARG(INT,num_outputs) ARG(INT_VEC,kernel_shape) ARG(INT,ceil_mode) ARG(INT_VEC,dilations) ARG(INT_VEC,pads) ARG(INT,storage_order) ARG(INT_VEC,strides) )
OP_DECL(popart_mod, aiOnnxOpset.mod, ARG(INT,fmod) )
OP_DECL(popart_nonmaxsuppression, aiOnnxOpset.nonmaxsuppression, ARG(INT,center_point_box) )
OP_DECL(popart_qlinearconv, aiOnnxOpset.qlinearconv, ARG(INT_VEC,dilations) ARG(INT,group) ARG(INT_VEC,kernel_shape) ARG(INT_VEC,pads) ARG(INT_VEC,strides) )
OP_DECL(popart_qlinearmatmul, aiOnnxOpset.qlinearmatmul, NONE)
OP_DECL(popart_quantizelinear, aiOnnxOpset.quantizelinear, NONE)
OP_DECL(popart_resize, aiOnnxOpset.resize, ARG(STRING,mode) )
OP_DECL(popart_reversesequence, aiOnnxOpset.reversesequence, ARG(INT,batch_axis) ARG(INT,time_axis) )
OP_DECL(popart_roialign, aiOnnxOpset.roialign, ARG(STRING,mode) ARG(INT,output_height) ARG(INT,output_width) ARG(INT,sampling_ratio) ARG(FLOAT,spatial_scale) )
OP_DECL(popart_slice, aiOnnxOpset.slice, NONE)
OP_DECL(popart_thresholdedrelu, aiOnnxOpset.thresholdedrelu, ARG(FLOAT,alpha) )
OP_DECL(popart_topk, aiOnnxOpset.topk, ARG(INT,axis) )
OP_DECL(popart_upsample, aiOnnxOpset.upsample, ARG(STRING,mode) )
// Ops from AiOnnxOpset9
OP_DECL(popart_acosh, aiOnnxOpset.acosh, NONE)
OP_DECL(popart_asinh, aiOnnxOpset.asinh, NONE)
OP_DECL(popart_atanh, aiOnnxOpset.atanh, NONE)
// OP_DECL(popart_batchnormalization, aiOnnxOpset.batchnormalization, ARG(INT,num_outputs) ARG(FLOAT,epsilon) ARG(FLOAT,momentum) )
OP_DECL(popart_cast, aiOnnxOpset.cast, ARG(STRING,to) )
OP_DECL(popart_compress, aiOnnxOpset.compress, ARG(INT,axis) )
OP_DECL(popart_cosh, aiOnnxOpset.cosh, NONE)
OP_DECL(popart_erf, aiOnnxOpset.erf, NONE)
OP_DECL(popart_eyelike, aiOnnxOpset.eyelike, ARG(INT,dtype) ARG(INT,k) )
OP_DECL(popart_flatten, aiOnnxOpset.flatten, ARG(INT,axis) )
OP_DECL(popart_gemm, aiOnnxOpset.gemm, ARG(FLOAT,alpha) ARG(FLOAT,beta) ARG(INT,transA) ARG(INT,transB) )
OP_DECL(popart_greater, aiOnnxOpset.greater, NONE)
OP_DECL(popart_isnan, aiOnnxOpset.isnan, NONE)
OP_DECL(popart_less, aiOnnxOpset.less, NONE)
OP_DECL(popart_matmul, aiOnnxOpset.matmul, NONE)
OP_DECL(popart_maxunpool, aiOnnxOpset.maxunpool, ARG(INT_VEC,kernel_shape) ARG(INT_VEC,pads) ARG(INT_VEC,strides) )
OP_DECL(popart_meanvariancenormalization, aiOnnxOpset.meanvariancenormalization, ARG(INT_VEC,axes) )
OP_DECL(popart_nonzero, aiOnnxOpset.nonzero, NONE)
OP_DECL(popart_onehot, aiOnnxOpset.onehot, ARG(INT,axis) )
OP_DECL(popart_prelu, aiOnnxOpset.prelu, NONE)
OP_DECL(popart_scatter, aiOnnxOpset.scatter, ARG(INT,axis) )
OP_DECL(popart_shrink, aiOnnxOpset.shrink, ARG(FLOAT,bias) ARG(FLOAT,lambd) )
OP_DECL(popart_sign, aiOnnxOpset.sign, NONE)
OP_DECL(popart_sinh, aiOnnxOpset.sinh, NONE)
// OP_DECL(popart_tfidfvectorizer, aiOnnxOpset.tfidfvectorizer, ARG(INT,max_gram_length) ARG(INT,max_skip_count) ARG(INT,min_gram_length) ARG(STRING,mode) ARG(INT_VEC,ngram_counts) ARG(INT_VEC,ngram_indexes) ARG(INT_VEC,pool_int64s) ARG(STRING_VEC,pool_strings) ARG(FLOAT_VEC,weights) )
OP_DECL(popart_where, aiOnnxOpset.where, NONE)
// Ops from AiOnnxOpset8
OP_DECL(popart_expand, aiOnnxOpset.expand, NONE)
OP_DECL(popart_max, aiOnnxOpset.max, NONE)
OP_DECL(popart_mean, aiOnnxOpset.mean, NONE)
OP_DECL(popart_min, aiOnnxOpset.min, NONE)
OP_DECL(popart_sum, aiOnnxOpset.sum, NONE)
// Ops from AiOnnxOpset7
OP_DECL(popart_acos, aiOnnxOpset.acos, NONE)
OP_DECL(popart_add, aiOnnxOpset.add, NONE)
OP_DECL(popart_logical_and, aiOnnxOpset.logical_and, NONE)
OP_DECL(popart_asin, aiOnnxOpset.asin, NONE)
OP_DECL(popart_atan, aiOnnxOpset.atan, NONE)
OP_DECL(popart_cos, aiOnnxOpset.cos, NONE)
OP_DECL(popart_div, aiOnnxOpset.div, NONE)
OP_DECL(popart_equal, aiOnnxOpset.equal, NONE)
OP_DECL(popart_mul, aiOnnxOpset.mul, NONE)
OP_DECL(popart_multinomial, aiOnnxOpset.multinomial, ARG(INT,dtype) ARG(INT,sample_size) ARG(FLOAT,seed) )
OP_DECL(popart_logical_or, aiOnnxOpset.logical_or, NONE)
OP_DECL(popart_pow, aiOnnxOpset.pow, NONE)
// OP_DECL(popart_rnn, aiOnnxOpset.rnn, ARG(INT,num_outputs) ARG(FLOAT_VEC,activation_alpha) ARG(FLOAT_VEC,activation_beta) ARG(STRING_VEC,activations) ARG(FLOAT,clip) ARG(STRING,direction) ARG(INT,hidden_size) )
OP_DECL(popart_sin, aiOnnxOpset.sin, NONE)
OP_DECL(popart_sub, aiOnnxOpset.sub, NONE)
OP_DECL(popart_tan, aiOnnxOpset.tan, NONE)
OP_DECL(popart_logical_xor, aiOnnxOpset.logical_xor, NONE)
// Ops from AiOnnxOpset6
OP_DECL(popart_abs, aiOnnxOpset.abs, NONE)
OP_DECL(popart_argmax, aiOnnxOpset.argmax, ARG(INT,axis) ARG(INT,keepdims) )
OP_DECL(popart_argmin, aiOnnxOpset.argmin, ARG(INT,axis) ARG(INT,keepdims) )
OP_DECL(popart_ceil, aiOnnxOpset.ceil, NONE)
// OP_DECL(popart_clip, aiOnnxOpset.clip, ARG(FLOAT,max) ARG(FLOAT,min) )
OP_DECL(popart_concat, aiOnnxOpset.concat, ARG(INT,axis) )
OP_DECL(popart_conv, aiOnnxOpset.conv, ARG(INT_VEC,dilations) ARG(INT,group) ARG(INT_VEC,kernel_shape) ARG(INT_VEC,pads) ARG(INT_VEC,strides) )
OP_DECL(popart_convtranspose, aiOnnxOpset.convtranspose, ARG(INT_VEC,dilations) ARG(INT,group) ARG(INT_VEC,kernel_shape) ARG(INT_VEC,output_padding) ARG(INT_VEC,output_shape) ARG(INT_VEC,pads) ARG(INT_VEC,strides) )
OP_DECL(popart_elu, aiOnnxOpset.elu, ARG(FLOAT,alpha) )
OP_DECL(popart_exp, aiOnnxOpset.exp, NONE)
OP_DECL(popart_floor, aiOnnxOpset.floor, NONE)
OP_DECL(popart_gather, aiOnnxOpset.gather, ARG(INT,axis) )
OP_DECL(popart_globalaveragepool, aiOnnxOpset.globalaveragepool, NONE)
OP_DECL(popart_globallppool, aiOnnxOpset.globallppool, ARG(INT,p) )
OP_DECL(popart_globalmaxpool, aiOnnxOpset.globalmaxpool, NONE)
OP_DECL(popart_hardsigmoid, aiOnnxOpset.hardsigmoid, ARG(FLOAT,alpha) ARG(FLOAT,beta) )
OP_DECL(popart_hardmax, aiOnnxOpset.hardmax, ARG(INT,axis) )
OP_DECL(popart_identity, aiOnnxOpset.identity, NONE)
OP_DECL(popart_instancenormalization, aiOnnxOpset.instancenormalization, ARG(FLOAT,epsilon) )
OP_DECL(popart_lrn, aiOnnxOpset.lrn, ARG(INT,size) ARG(FLOAT,alpha) ARG(FLOAT,beta) ARG(FLOAT,bias) )
OP_DECL(popart_leakyrelu, aiOnnxOpset.leakyrelu, ARG(FLOAT,alpha) )
OP_DECL(popart_log, aiOnnxOpset.log, NONE)
OP_DECL(popart_logsoftmax, aiOnnxOpset.logsoftmax, ARG(INT,axis) )
OP_DECL(popart_lpnormalization, aiOnnxOpset.lpnormalization, ARG(INT,axis) ARG(INT,p) )
OP_DECL(popart_lppool, aiOnnxOpset.lppool, ARG(INT_VEC,kernel_shape) ARG(INT,p) ARG(INT_VEC,pads) ARG(INT_VEC,strides) )
OP_DECL(popart_maxroipool, aiOnnxOpset.maxroipool, ARG(INT_VEC,pooled_shape) ARG(FLOAT,spatial_scale) )
OP_DECL(popart_neg, aiOnnxOpset.neg, NONE)
OP_DECL(popart_logical_not, aiOnnxOpset.logical_not, NONE)
// OP_DECL(popart_pad, aiOnnxOpset.pad, ARG(INT_VEC,pads) ARG(STRING,mode) ARG(FLOAT,value) )
OP_DECL(popart_randomnormallike, aiOnnxOpset.randomnormallike, ARG(INT,dtype) ARG(FLOAT,mean) ARG(FLOAT,scale) ARG(FLOAT,seed) )
OP_DECL(popart_randomuniformlike, aiOnnxOpset.randomuniformlike, ARG(INT,dtype) ARG(FLOAT,high) ARG(FLOAT,low) ARG(FLOAT,seed) )
OP_DECL(popart_reciprocal, aiOnnxOpset.reciprocal, NONE)
OP_DECL(popart_reducel1, aiOnnxOpset.reducel1, ARG(INT_VEC,axes) ARG(INT,keepdims) )
OP_DECL(popart_reducel2, aiOnnxOpset.reducel2, ARG(INT_VEC,axes) ARG(INT,keepdims) )
OP_DECL(popart_reducelogsum, aiOnnxOpset.reducelogsum, ARG(INT_VEC,axes) ARG(INT,keepdims) )
OP_DECL(popart_reducelogsumexp, aiOnnxOpset.reducelogsumexp, ARG(INT_VEC,axes) ARG(INT,keepdims) )
OP_DECL(popart_reducemax, aiOnnxOpset.reducemax, ARG(INT_VEC,axes) ARG(INT,keepdims) )
// OP_DECL(popart_reducemean, aiOnnxOpset.reducemean, ARG(INT_VEC,axes) ARG(INT,keepdims) )
OP_DECL(popart_reducemin, aiOnnxOpset.reducemin, ARG(INT_VEC,axes) ARG(INT,keepdims) )
OP_DECL(popart_reduceprod, aiOnnxOpset.reduceprod, ARG(INT_VEC,axes) ARG(INT,keepdims) )
OP_DECL(popart_reducesum, aiOnnxOpset.reducesum, ARG(INT_VEC,axes) ARG(INT,keepdims) )
OP_DECL(popart_reducesumsquare, aiOnnxOpset.reducesumsquare, ARG(INT_VEC,axes) ARG(INT,keepdims) )
OP_DECL(popart_relu, aiOnnxOpset.relu, NONE)
OP_DECL(popart_selu, aiOnnxOpset.selu, ARG(FLOAT,alpha) ARG(FLOAT,gamma) )
OP_DECL(popart_shape, aiOnnxOpset.shape, NONE)
OP_DECL(popart_sigmoid, aiOnnxOpset.sigmoid, NONE)
OP_DECL(popart_size, aiOnnxOpset.size, NONE)
OP_DECL(popart_softmax, aiOnnxOpset.softmax, ARG(INT,axis) )
OP_DECL(popart_softplus, aiOnnxOpset.softplus, NONE)
OP_DECL(popart_softsign, aiOnnxOpset.softsign, NONE)
OP_DECL(popart_spacetodepth, aiOnnxOpset.spacetodepth, ARG(INT,blocksize) )
OP_DECL(popart_split, aiOnnxOpset.split, ARG(INT,num_outputs) ARG(INT,axis) ARG(INT_VEC,split) )
OP_DECL(popart_sqrt, aiOnnxOpset.sqrt, NONE)
OP_DECL(popart_squeeze, aiOnnxOpset.squeeze, ARG(INT_VEC,axes) )
OP_DECL(popart_tanh, aiOnnxOpset.tanh, NONE)
OP_DECL(popart_tile, aiOnnxOpset.tile, NONE)
OP_DECL(popart_transpose, aiOnnxOpset.transpose, ARG(INT_VEC,perm) )
OP_DECL(popart_unsqueeze, aiOnnxOpset.unsqueeze, ARG(INT_VEC,axes) )
