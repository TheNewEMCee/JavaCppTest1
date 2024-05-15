cmake_minimum_required(VERSION 3.27)
project(JavaCppTest1)

set(CMAKE_CXX_STANDARD 23)

add_executable(JavaCppTest1 cpp/main.cpp
        cpp/CInt.h
        cpp/CInt.cpp)
