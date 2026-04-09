cmake_minimum_required(VERSION 3.26.5)
set(CMAKE_CXX_STANDARD 17)
project(ScorepProject)

option(WITH_THREADS "Build with support of OpenMP" OFF)
option(ENABLE_MPI "Enable Distributed-memory paralellization with MPI" OFF)
option(WITH_SCOREP "Build with Scorep" OFF)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set(CMAKE_BUILD_TYPE "Debug")

if(WITH_THREADS)
    set(SOURCES_openmp hello_world_openmp.cpp)
    find_package(OpenMP REQUIRED)
    add_executable(hello_world_openmp ${SOURCES_openmp})
    target_compile_features(hello_world_openmp PUBLIC cxx_std_17)
    target_compile_options(hello_world_openmp PRIVATE)
    target_link_options(hello_world_openmp PRIVATE)
    target_link_libraries(hello_world_openmp PUBLIC OpenMP::OpenMP_CXX)
endif()

if(ENABLE_MPI)
    set(SOURCES_mpi hello_world_mpi.cpp)
    find_package(MPI REQUIRED)
    add_executable(hello_world_mpi ${SOURCES_mpi})
    target_compile_features(hello_world_mpi PUBLIC cxx_std_17)
    target_compile_options(hello_world_mpi PRIVATE)
    target_link_options(hello_world_mpi PRIVATE)
    target_link_libraries(hello_world_mpi PUBLIC MPI::MPI_CXX)
endif()

if(WITH_SCOREP)
    set(SOURCES_openmp_scorep hello_world_openmp.cpp)
    set(SOURCES_mpi_scorep hello_world_mpi.cpp)
    find_package(OpenMP REQUIRED)
    find_package(MPI REQUIRED)
    find_package(Scorep REQUIRED)
    export mpicxx=scorep mpicxx
    export mpiexec=scorep mpiexec
    export mpirun=scorep mpirun
    export SCOREP_ENABLE_TRACING=true
    export SCOREP_ENABLE_PROFILING=true
    export gcc=scorep gcc
    export g++=scorep g++
    add_executable(hello_world_openmp ${SOURCES_openmp_scorep})
    add_executable(hello_world_mpi ${SOURCES_mpi_scorep})
    target_compile_features(hello_world_openmp PUBLIC cxx_std_17)
    target_compile_options(hello_world_openmp PRIVATE)
    target_link_options(hello_world_openmp PRIVATE)
    target_link_libraries(hello_world_openmp PUBLIC OpenMP::OpenMP_CXX)
    target_compile_features(hello_world_mpi PUBLIC cxx_std_17)
    target_compile_options(hello_world_mpi PRIVATE)
    target_link_options(hello_world_mpi PRIVATE)
    target_link_libraries(hello_world_mpi PUBLIC MPI::MPI_CXX)
endif()