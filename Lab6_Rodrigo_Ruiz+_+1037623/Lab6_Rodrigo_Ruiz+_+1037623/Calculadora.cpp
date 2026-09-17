#include "pch.h"
#include "Calculadora.h"
#include <cmath>

void Calculadora::Suma(int* resultado, int a, int b) {
    *resultado = a + b;
}

void Calculadora::Resta(int* resultado, int a, int b) {
    *resultado = a - b;
}

void Calculadora::Multiplicacion(int* resultado, int a, int b) {
    *resultado = a * b;
}

void Calculadora::Division(int* resultado, int a, int b) {
    *resultado = a / b;
}

void Calculadora::Potencia(int* resultado, int base, int exponente) {
    *resultado = (int)pow(base, exponente);
}

void Calculadora::Radicacion(int* resultado, int numero, int indice) {
    *resultado = (int)pow(numero, 1.0 / indice);
}
