cmake_minimum_required(VERSION 3.10)
project(high_performance_sorting)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3")

# Add source files
set(SOURCES
    src/main.cpp
    src/radix_sort.cpp
    src/parallel_merge_sort.cpp
    src/utils.cpp
)

# Add include directories
include_directories(include src)

# Create the executable
add_executable(high_performance_sorting ${SOURCES})

# Link with pthread for multithreading
target_link_libraries(high_performance_sorting pthread)

# Add testing
enable_testing()
add_subdirectory(tests)

# Add benchmarking
add_subdirectory(benchmarks)
