#include <torch/extension.h>
#include "function_cuda.hpp"

#define CHECK_CUDA(x) \
  AT_ASSERTM(x.type().is_cuda(), #x " must be a CUDA tensor")
#define CHECK_CONTIGUOUS(x) \
  AT_ASSERTM(x.is_contiguous(), #x " must be contiguous")
#define CHECK_INPUT(x) \
  CHECK_CUDA(x);       \
  CHECK_CONTIGUOUS(x)

void function(at::Tensor x) {
	CHECK_INPUT(x);
	function_cuda(x);
}

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
  m.def("function", &function, "a function");
}
