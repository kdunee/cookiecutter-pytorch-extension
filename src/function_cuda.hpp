#pragma once

#include <torch/extension.h>

void function_cuda(at::Tensor x);
