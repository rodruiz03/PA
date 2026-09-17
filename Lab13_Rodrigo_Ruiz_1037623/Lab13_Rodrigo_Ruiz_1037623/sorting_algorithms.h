#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>
#include <tuple>
#include <ctime>

std::tuple<int, std::vector<int>, double> bubbleSort(std::vector<int> arr);
std::tuple<int, std::vector<int>, double> selectionSort(std::vector<int> arr);

#endif // SORTING_ALGORITHMS_H
