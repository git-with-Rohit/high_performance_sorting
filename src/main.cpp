#include <iostream>
#include <vector>
#include "timsort.h"
#include "radix_sort.h"
#include "parallel_merge_sort.h"

int main() {
    std::vector<int> data = {5, 3, 8, 4, 2};

    // Timsort
    timsort(data);
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Radix Sort
    radix_sort(data);
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Parallel Merge Sort
    parallel_merge_sort(data);
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
