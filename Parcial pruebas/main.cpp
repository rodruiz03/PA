#include <iostream>

 void BubbleSort(int* a, int length){
    for (int i = 0; i < length; ++i) {
        for (int j = i+1; j < length; ++j) {
            if (a[i] < a[j]){
                // cumplido
                continue;
            } else {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

void SelectionSort(int* a, int length){
    for (int i = 0; i < length; ++i) {
        int indice_menor = i;
        for (int j = i+1; j < length; ++j) {
            if (a[indice_menor] < a[j]){
                // cumplido
                continue;
            } else {
                indice_menor = j;
            }
        }
        int t = a[indice_menor];
        a[indice_menor] = a[i];
        a[i] = t;
    }
}

int partition(int* a, int start, int end){
    int pivot = a[start];
    // Contamos cuantos valores son mas pequenios que el pivote
    int count = 0;
    for (int i = start+1; i <= end; ++i) {
        if (a[i] < pivot){
            count++;
        }
    }
    // pivotIndex sera la posicion que el valor del pivote
    // debe ocupar en el arreglo (en este punto ya lo sabemos)
    int pivotIndex = start + count;
    // Ordenamos el pivot en su posicion correcta (pivotIndex)
    int t = a[pivotIndex];
    a[pivotIndex] = a[start];
    a[start] = t;

    // empieza el ordenamiento por subgrupos
    int _menoresIndex = start;
    int _mayoresIndex = end;

    while (_menoresIndex < pivotIndex && _mayoresIndex >  pivotIndex){
        // buscar el primer elemento que sea mayor al pivote
        while(a[_menoresIndex] < pivot){
            _menoresIndex++;
        }

        // buscar el primer elemento que sea menor al pivote
        while (a[_mayoresIndex] > pivot){
            _mayoresIndex--;
        }

        // aca encontre un par de numeros que estan de los datos
        // incorrectos
        if (_menoresIndex < pivotIndex && _mayoresIndex >  pivotIndex){
            t = a[_menoresIndex];
            a[_menoresIndex] = a[_mayoresIndex];
            a[_mayoresIndex] = t;
            _menoresIndex++;
            _mayoresIndex--;
        }
    }
    return pivotIndex;
}

void quicksort(int* a, int start, int end){
    if (start >= end) return;
    int pivotIndex = partition(a, start, end);
    // ordenar el lado izquierdo, los menores
    quicksort(a, start, pivotIndex -1);

    // ordenar el lado derecho, los mayores
    quicksort(a, pivotIndex + 1, end);
}


int main() {
    int* a = new int[10] { 6, 2, 8, 7, 9, 10, 6, 2, 1, 0};

    for (int i = 0; i < 10; ++i) {
        std::cout << a[i] << " ";
    }
    quicksort(a, 0, 9);
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << a[i] << " ";
    }
    return 0;
}
