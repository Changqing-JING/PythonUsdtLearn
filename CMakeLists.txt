cmake_minimum_required(VERSION 3.10)
project(UsdtLearn)
aux_source_directory(cpp_example sourceFiles)
add_executable(cpp_example ${sourceFiles})