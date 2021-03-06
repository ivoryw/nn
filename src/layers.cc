#include "layers.hpp"
#include <string>
#include <cmath>

namespace nn{

using autodiff::Var;

static std::string dim_err ="Input tensors to fully connected layers must be 1D tensors";

FullyConnected::FullyConnected(size_t in_size, size_t out_size, Net* net)
: weight(net->create_parameter(Tensor(in_size, out_size))),
  bias (net->create_parameter(Tensor(1, out_size))) {
    weight.randn();
    bias.randn();
}
    
Var FullyConnected::operator()(const Var& input){
    auto result = weight * input;
    result += bias;
    return result;
}

//Conv1d::Conv1d(Net* net, size_t c_in, size_t c_out, size_t kernel, size_t padding, size_t stride)
//: weight(net, c_out, c_in, kernel, kernel), bias(net, c_out),
// out_channels(c_out), kernel(kernel), padding(padding), stride(stride){
//    weight.randn();
//    bias.randn();
//}

//autodiff::Var Conv1d::operator()(const autodiff::Var& input){
//    auto r_len = floor((input.data.shape[1] + 2*padding - (kernel - 1) -1)/stride+1);
//    autodiff::Var result(out_channels, r_len);
//    result += conv_1d(input, weight);
//    result += bias;
//    return result;
//}


//Conv2d::Conv2d(Net* net, size_t c_in, size_t c_out, size_t kernel, size_t padding, size_t stride)
//: weight(net, c_out, c_in, kernel, kernel), bias(net, c_out), 
//out_channels(c_out), kernel(kernel), padding(padding), stride(stride){
//    weight.randn();
//    bias.randn();
//}
//
//autodiff::var Conv2d::operator()(const autodiff::var& input){
//    auto r_height = floor((input.data.shape[1] + 2*padding - (kernel - 1) -1)/stride + 1);
//    auto r_width = floor((input.data.shape[0] + 2*padding - (kernel - 1) - 1)/stride + 1);
//    autodiff::var result(out_channels, r_width, r_height);
//    result = conv2d(input, weight, stride, kernel); 
//    result += bias;
//    return result;
//}
} // namespace nn
