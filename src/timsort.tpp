#ifndef TIMSORT_TPP
#define TIMSORT_TPP

#include "timsort.h"

const int MIN_RUN = 32;

// Insertion sort
template<typename T>
void insertion_sort(std::vector<T>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        T temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;
    }
}

// Merge function for Timsort
template<typename T>
void timsort_merge(std::vector<T>& arr, int l, int m, int r) { // Renamed from merge to timsort_merge
    int len1 = m - l + 1, len2 = r - m;
    std::vector<T> left(len1), right(len2);
    for (int i = 0; i < len1; ++i) left[i] = arr[l + i];
    for (int i = 0; i < len2; ++i) right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < len1) arr[k++] = left[i++];
    while (j < len2) arr[k++] = right[j++];
}

// Timsort implementation
template<typename T>
void timsort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i += MIN_RUN) {
        insertion_sort(arr, i, std::min(i + MIN_RUN - 1, n - 1));
    }

    for (int size = MIN_RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = std::min(left + size - 1, n - 1);
            int right = std::min(left + 2 * size - 1, n - 1);

            if (mid < right) {
                timsort_merge(arr, left, mid, right); // Updated function name
            }
        }
    }
}

// Explicit instantiation
template void timsort<int>(std::vector<int>& arr);

#endif // TIMSORT_TPP
