# Platform-independent Makefile - requires cmake 2.6 or higher
cmake_minimum_required(VERSION 2.6)

# Source code is written in:
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Static source code analysis:
# set(CMAKE_CXX_CPPCHECK "cppcheck")

project(base256)

add_executable(base256 base256.cpp)
