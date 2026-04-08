cmake_minimum_required(VERSION 3.26.5)
project(openmpProject)
find_package(OpenMP REQUIRED)
find_package(MPI REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set(CMAKE_BUILD_TYPE "Debug")
set(SOURCES hello_world_openmp.cpp)

add_executable(hello_world_openmp ${SOURCES})
target_compile_features(hello_world_openmp PUBLIC cxx_std_17)

target_compile_options(hello_world_openmp PRIVATE)
target_link_options(hello_world_openmp PRIVATE)
target_link_libraries(hello_world_openmp PUBLIC OpenMP::OpenMP_CXX)