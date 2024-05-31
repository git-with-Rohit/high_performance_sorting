# Download and unpack Google Benchmark at configure time
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../googlebenchmark-CMakeLists.txt.in ${CMAKE_BINARY_DIR}/googlebenchmark-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googlebenchmark-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googlebenchmark-download )

# Add Google Benchmark directly to our build. This defines the benchmark and benchmark_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googlebenchmark-download/googlebenchmark-prefix/src/googlebenchmark
                 ${CMAKE_BINARY_DIR}/googlebenchmark-download/googlebenchmark-prefix/src/googlebenchmark-build
                 EXCLUDE_FROM_ALL)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)

# Link Google Benchmark to our benchmarks
add_executable(benchmark_app benchmark.cpp ${PROJECT_SOURCE_DIR}/src/radix_sort.cpp)
target_link_libraries(benchmark_app benchmark::benchmark pthread)

# Register the benchmark executable with CTest
add_test(NAME benchmark_app COMMAND benchmark_app)
