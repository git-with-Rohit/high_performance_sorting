#include <benchmark/benchmark.h>
#include "timsort.h"
#include "radix_sort.h"
#include "parallel_merge_sort.h"

static void BM_TimSort(benchmark::State& state) {
    std::vector<int> data(state.range(0));
    std::generate(data.begin(), data.end(), std::rand);
    for (auto _ : state) {
        timsort(data);
    }
}

static void BM_RadixSort(benchmark::State& state) {
    std::vector<int> data(state.range(0));
    std::generate(data.begin(), data.end(), std::rand);
    for (auto _ : state) {
        radix_sort(data);
    }
}

static void BM_ParallelMergeSort(benchmark::State& state) {
    std::vector<int> data(state.range(0));
    std::generate(data.begin(), data.end(), std::rand);
    for (auto _ : state) {
        parallel_merge_sort(data);
    }
}

BENCHMARK(BM_TimSort)->Range(8, 8<<10);
BENCHMARK(BM_RadixSort)->Range(8, 8<<10);
BENCHMARK(BM_ParallelMergeSort)->Range(8, 8<<10);

BENCHMARK_MAIN();
