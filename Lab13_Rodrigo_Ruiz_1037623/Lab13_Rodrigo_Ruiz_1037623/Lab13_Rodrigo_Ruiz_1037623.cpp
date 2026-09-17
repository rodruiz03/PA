#include "pch.h"
#include "sorting_algorithms.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> generateRandomArray(size_t size) {
    std::vector<int> arr(size);
    for (size_t i = 0; i < size; ++i) {
        arr[i] = rand() % 100; // Números aleatorios entre 0 y 99
    }
    return arr;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    size_t size;
    std::cout << "Ingrese la cantidad de elementos del arreglo: ";
    std::cin >> size;

    std::vector<int> arr = generateRandomArray(size);

    auto [bubbleComparisons, bubbleSortedArray, bubbleTime] = bubbleSort(arr);
    auto [selectionComparisons, selectionSortedArray, selectionTime] = selectionSort(arr);

    std::cout << "Ordenamiento por Burbuja:\n";
    std::cout << "Comparaciones: " << bubbleComparisons << "\n";
    std::cout << "Tiempo: " << bubbleTime << " segundos\n";

    std::cout << "\nOrdenamiento por Seleccion:\n";
    std::cout << "Comparaciones: " << selectionComparisons << "\n";
    std::cout << "Tiempo: " << selectionTime << " segundos\n";

    return 0;
}
