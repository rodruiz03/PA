#include "pch.h"

#include <iostream>
using namespace std;

const int N = 4; // Tamaño de la matriz NxN

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void rotateMatrix(int matrix[N][N]) {
    // Transponer la matriz
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Invertir cada fila
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N / 2; j++) {
            swap(matrix[i][j], matrix[i][N - j - 1]);
        }
    }
}

int main() {
    int matrix[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    rotateMatrix(matrix);

    cout << "Rotated Matrix:" << endl;
    printMatrix(matrix);

    return 0;
}
