#include "pch.h"
#include <iostream>
#include <string>

using namespace System;


// Función recursiva para calcular la suma de un arreglo de enteros
int sumaArreglo(int* arreglo, int size) {
    if (size == 0) {
        return 0;
    }
    else {
        return arreglo[size - 1] + sumaArreglo(arreglo, size - 1);
    }
}

// Función recursiva para ordenar un arreglo de enteros de menor a mayor
void ordenarArreglo(int* arreglo, int size) {
    if (size <= 1) {
        return;
    }

    int indiceMenor = 0;
    for (int i = 1; i < size; i++) {
        if (arreglo[i] < arreglo[indiceMenor]) {
            indiceMenor = i;
        }
    }

    int temp = arreglo[0];
    arreglo[0] = arreglo[indiceMenor];
    arreglo[indiceMenor] = temp;

    ordenarArreglo(arreglo + 1, size - 1);
}

// Función recursiva para calcular el máximo común divisor (MCD) utilizando el algoritmo de Euclides
int mcd(int m, int n) {
    if (n == 0) {
        return m;
    }
    else {
        return mcd(n, m % n);
    }
}

// Función recursiva para transformar un número entero positivo a notación binaria
void decimalToBinary(int n) {
    if (n == 0) {
        return;
    }
    decimalToBinary(n / 2);
    std::cout << n % 2;
}

// Función recursiva para transformar un número expresado en notación binaria a un número entero
int binaryToDecimal(const std::string& binario, int indice) {
    if (indice < 0) {
        return 0;
    }
    if (binario[indice] == '1') {
        return (1 << (binario.size() - indice - 1)) + binaryToDecimal(binario, indice - 1);
    }
    else {
        return binaryToDecimal(binario, indice - 1);
    }
}

int main() {
    // Ejercicio 1: Suma de un arreglo de enteros
    int arreglo1[] = { 1, 2, 3, 4, 5 };
    int size1 = sizeof(arreglo1) / sizeof(arreglo1[0]);
    int suma = sumaArreglo(arreglo1, size1);
    std::cout << "La suma del arreglo es: " << suma << std::endl;

    // Ejercicio 2: Ordenar un arreglo de enteros de menor a mayor
    int arreglo2[] = { 5, 3, 1, 4, 2 };
    int size2 = sizeof(arreglo2) / sizeof(arreglo2[0]);
    ordenarArreglo(arreglo2, size2);

    std::cout << "Arreglo ordenado: ";
    for (int i = 0; i < size2; i++) {
        std::cout << arreglo2[i] << " ";
    }
    std::cout << std::endl;

    // Ejercicio 3: Calcular el máximo común divisor (MCD) de dos enteros positivos
    int m = 24;
    int n = 36;
    int resultado = mcd(m, n);
    std::cout << "El MCD de " << m << " y " << n << " es: " << resultado << std::endl;

    // Ejercicio 4: Transformar un número entero positivo a notación binaria
    int numero = 13;
    std::cout << "La notacion binaria de " << numero << " es: ";
    decimalToBinary(numero);
    std::cout << std::endl;

    // Ejercicio 5: Transformar un número expresado en notación binaria a un número entero
    std::string binario = "1101";
    int decimal = binaryToDecimal(binario, binario.size() - 1);
    std::cout << "El numero entero de " << binario << " en binario es: " << decimal << std::endl;

    return 0;
}