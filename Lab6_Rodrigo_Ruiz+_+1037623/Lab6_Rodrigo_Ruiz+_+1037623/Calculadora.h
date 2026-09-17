#pragma once
ref class Calculadora
{
public:
    static void Suma(int* resultado, int a, int b);
    static void Resta(int* resultado, int a, int b);
    static void Multiplicacion(int* resultado, int a, int b);
    static void Division(int* resultado, int a, int b);
    static void Potencia(int* resultado, int base, int exponente);
    static void Radicacion(int* resultado, int numero, int indice);
};

