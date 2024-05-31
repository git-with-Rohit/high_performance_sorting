#ifndef PARALLEL_MERGE_SORT_H
#define PARALLEL_MERGE_SORT_H

#include <vector>

/**
 * Sorts the given vector using the Parallel Merge Sort algorithm.
 * @param arr The vector to be sorted.
 */
template<typename T>
void parallel_merge_sort(std::vector<T>& arr);

#include "parallel_merge_sort.tpp"

#endif // PARALLEL_MERGE_SORT_H
