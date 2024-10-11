# Platform-independent CMakefile to build base256U
# ------------------------------------------------

cmake_minimum_required (VERSION 3.5)

project (base256U)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

add_executable (base256U base256U.cpp)

install (TARGETS base256U DESTINATION . )
