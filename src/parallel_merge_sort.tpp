#ifndef PARALLEL_MERGE_SORT_TPP
#define PARALLEL_MERGE_SORT_TPP

#include "parallel_merge_sort.h"
#include <thread> // Added

template<typename T>
void parallel_merge_sort_merge(std::vector<T>& arr, int left, int mid, int right) { // Renamed from merge to parallel_merge_sort_merge
    int len1 = mid - left + 1, len2 = right - mid;
    std::vector<T> leftArr(len1), rightArr(len2);

    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < len2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < len1 && j < len2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < len1)
        arr[k++] = leftArr[i++];
    while (j < len2)
        arr[k++] = rightArr[j++];
}

template<typename T>
void parallel_merge_sort_helper(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        std::thread leftThread(parallel_merge_sort_helper<T>, std::ref(arr), left, mid);
        std::thread rightThread(parallel_merge_sort_helper<T>, std::ref(arr), mid + 1, right);

        leftThread.join();
        rightThread.join();

        parallel_merge_sort_merge(arr, left, mid, right); // Updated function name
    }
}

template<typename T>
void parallel_merge_sort(std::vector<T>& arr) {
    parallel_merge_sort_helper(arr, 0, arr.size() - 1);
}

// Explicit instantiation
template void parallel_merge_sort<int>(std::vector<int>& arr);

#endif // PARALLEL_MERGE_SORT_TPP
