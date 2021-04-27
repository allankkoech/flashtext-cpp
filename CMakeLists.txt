cmake_minimum_required(VERSION 3.19)
project(flashtext_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(flashtext_cpp examples/main.cpp src/flashtext.cpp)