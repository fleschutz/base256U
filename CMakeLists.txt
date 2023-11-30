# Platform-independent Makefile for CMake

cmake_minimum_required(VERSION 3.5)

project(base256)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(base256 base256.cpp)

install(TARGETS base256 DESTINATION .)
