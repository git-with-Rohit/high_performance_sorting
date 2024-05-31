#include "radix_sort.h"
#include <vector>

// Utility function to get maximum value in arr[]
int getMax(const std::vector<int>& arr) {
    int mx = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(std::vector<int>& arr, int exp) {
    std::vector<int> output(arr.size()); // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < arr.size(); i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using Radix Sort
void radix_sort(std::vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int m = getMax(arr);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
}
