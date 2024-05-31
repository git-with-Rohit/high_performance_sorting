# Download and unpack googletest at configure time
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../googletest-CMakeLists.txt.in ${CMAKE_BINARY_DIR}/googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

# Add googletest directly to our build. This defines the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)

# Link googletest to our tests
add_executable(test_timsort test_timsort.cpp)
target_link_libraries(test_timsort gtest gtest_main pthread)
add_test(NAME test_timsort COMMAND test_timsort)

add_executable(test_radix_sort test_radix_sort.cpp ${PROJECT_SOURCE_DIR}/src/radix_sort.cpp)
target_link_libraries(test_radix_sort gtest gtest_main pthread)
add_test(NAME test_radix_sort COMMAND test_radix_sort)

add_executable(test_parallel_merge_sort test_parallel_merge_sort.cpp ${PROJECT_SOURCE_DIR}/src/parallel_merge_sort.cpp)
target_link_libraries(test_parallel_merge_sort gtest gtest_main pthread)
add_test(NAME test_parallel_merge_sort COMMAND test_parallel_merge_sort)
