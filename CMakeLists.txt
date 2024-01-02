# Platform-independent CMakefile to build Base256
# -----------------------------------------------

cmake_minimum_required (VERSION 3.5)

project (base256)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

add_executable (base256 main.cpp)

install (TARGETS base256 DESTINATION . )
