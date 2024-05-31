#ifndef TIMSORT_H
#define TIMSORT_H

#include <vector>
#include <algorithm>

/**
 * Sorts the given vector using the Timsort algorithm.
 * @param arr The vector to be sorted.
 */
template<typename T>
void timsort(std::vector<T>& arr);

#include "../src/timsort.tpp"

#endif // TIMSORT_H
