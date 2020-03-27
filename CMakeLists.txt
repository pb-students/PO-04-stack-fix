cmake_minimum_required(VERSION 3.16)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)

add_executable(stack main.cpp stack.h)
add_executable(stack-test test.cpp stack.h)
