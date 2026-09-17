#include "pch.h"
#include "sorting_algorithms.h"
#include <chrono>

std::tuple<int, std::vector<int>, double> bubbleSort(std::vector<int> arr) {
    size_t n = arr.size();
    int comparisons = 0;
    bool swapped;
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < n - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < n - 1 - i; ++j) {
            ++comparisons;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double time_taken = duration.count();

    return std::make_tuple(comparisons, arr, time_taken);
}

std::tuple<int, std::vector<int>, double> selectionSort(std::vector<int> arr) {
    size_t n = arr.size();
    int comparisons = 0;
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < n - 1; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; ++j) {
            ++comparisons;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double time_taken = duration.count();

    return std::make_tuple(comparisons, arr, time_taken);
}

