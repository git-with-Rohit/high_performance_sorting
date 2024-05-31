# High Performance Sorting

[![Build Status](https://img.shields.io/travis/git-with-Rohit/high_performance_sorting.svg)](https://travis-ci.org/git-with-Rohit/high_performance_sorting)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![GitHub issues](https://img.shields.io/github/issues/git-with-Rohit/high_performance_sorting.svg)](https://github.com/git-with-Rohit/high_performance_sorting/issues)
[![GitHub stars](https://img.shields.io/github/stars/git-with-Rohit/high_performance_sorting.svg)](https://github.com/git-with-Rohit/high_performance_sorting/stargazers)

High Performance Sorting is a C++ library providing efficient implementations of various sorting algorithms optimised for speed and scalability. This project aims to deliver high-performance sorting solutions for large datasets, leveraging parallel processing techniques and advanced algorithms.

## Features

- **TimSort**: A highly efficient sorting algorithm based on merge sort and insertion sort, optimised for real-world data.
- **Radix Sort**: A non-comparative integer sorting algorithm that sorts data with integer keys by grouping digits.
- **Parallel Merge Sort**: A parallelised version of merge sort designed to take advantage of multiple processor cores for faster sorting.

## Why High Performance Sorting?

- **Optimised for Speed**: Each sorting algorithm is carefully designed and implemented for maximum performance, ensuring rapid sorting of large datasets.
- **Scalability**: With support for parallel processing, High Performance Sorting can efficiently handle increasingly larger datasets as computational resources scale.
- **Easy Integration**: The library is designed to be easy to integrate into existing C++ projects, with simple and intuitive APIs.

## Quick Start

### Clone the Repository

```bash
git clone https://github.com/git-with-Rohit/high_performance_sorting.git
cd high_performance_sorting
```

## Build and Run Tests
1. Configure the project:
    ```bash
    mkdir build && cd build
    cmake ..
    ```

2. Build the project:
    ```bash
    make
    ```

3. Run tests:
    ```bash
    ./tests/test_timsort
    ./tests/test_radix_sort
    ./tests/test_parallel_merge_sort
    ```

# Contributing
Contributions are welcome! If you have ideas for new features, find bugs, or want to improve documentation, feel free to open an issue or submit a pull request.

Thank you for checking this out!

Rohit Kumar  
[GitHub](https://github.com/git-with-Rohit) | [LinkedIn](https://www.linkedin.com/in/itz-rohit/)