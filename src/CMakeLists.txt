# Cross-platform CMake Build Instructions for base256U
# ====================================================

cmake_minimum_required(VERSION 3.10)

project(base256U)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(base256U base256U.cpp)

enable_testing()
add_test(NAME base256U COMMAND base256U)

install(TARGETS base256U DESTINATION . )

