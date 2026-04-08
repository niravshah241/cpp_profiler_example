cmake_minimum_required(VERSION 3.26.5)
project(openmpProject)
find_package(OpenMP REQUIRED)
include_directories(SYSTEM 

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set(CMAKE_BUILD_TYPE "Debug")
set(SOURCES hello_world_openmp.cpp)



