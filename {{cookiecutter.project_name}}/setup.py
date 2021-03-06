from setuptools import setup
from torch.utils.cpp_extension import BuildExtension, CUDAExtension

sources = ['src/function.cpp', 'src/function_cuda.cu']

setup(
    name='{{cookiecutter.project_name}}',
    version='0.1',
    ext_modules=[
        CUDAExtension(
            name='{{cookiecutter.project_name}}',
            sources=sources),
    ],
    cmdclass={
        'build_ext': BuildExtension
    })
