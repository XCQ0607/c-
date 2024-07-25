cmake_minimum_required(VERSION 3.18)

project(CPP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp)
target_compile_features(main PRIVATE cxx_std_20)
