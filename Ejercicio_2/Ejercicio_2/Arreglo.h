#include <iostream>
#pragma once
#ifndef ARREGLO_H
#define ARREGLO_H

ref class Arreglo
{
private:
    char* _arreglo;
    int _longitud;
public:
    Arreglo(int longitud);
    ~Arreglo();
    char cambiarValorEnIndice(int indice, char valor);
    int agregarElementoAlFinal(char valor);
    void eliminarElementoAlFinal();
    void imprimir(int inicio = 0, int fin = -1);
    int buscarValor(char valor);
};

#endif // ARREGLO_H
