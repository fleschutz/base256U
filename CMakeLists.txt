# Platform-independent Makefile for CMake
# =======================================
cmake_minimum_required (VERSION 2.6)

project (base256)

# Source code is written in:
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Static source code analysis:
# set(CMAKE_CXX_CPPCHECK "cppcheck")

add_executable(base256 base256.cpp)

install (TARGETS base256 DESTINATION .)
