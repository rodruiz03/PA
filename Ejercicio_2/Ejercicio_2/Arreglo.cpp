#include "pch.h"
#include "Arreglo.h"
#include <iostream>
Arreglo::Arreglo(int longitud) : _longitud(longitud) {
    _arreglo = new char[longitud];
    for (int i = 0; i < _longitud; ++i) {
        _arreglo[i] = '?';
    }
}

Arreglo::~Arreglo() {
    delete[] _arreglo;
}

char Arreglo::cambiarValorEnIndice(int indice, char valor) {
    if (indice < 0 || indice >= _longitud) {
        std::cerr << "Índice fuera de rango." << std::endl;
        return '\0';
    }
    char antiguoValor = _arreglo[indice];
    _arreglo[indice] = valor;
    return antiguoValor;
}

int Arreglo::agregarElementoAlFinal(char valor) {
    char* nuevoArreglo = new char[_longitud + 1];
    for (int i = 0; i < _longitud; ++i) {
        nuevoArreglo[i] = _arreglo[i];
    }
    nuevoArreglo[_longitud] = valor;
    delete[] _arreglo;
    _arreglo = nuevoArreglo;
    ++_longitud;
    return _longitud;
}

void Arreglo::eliminarElementoAlFinal() {
    if (_longitud > 0) {
        char* nuevoArreglo = new char[_longitud - 1];
        for (int i = 0; i < _longitud - 1; ++i) {
            nuevoArreglo[i] = _arreglo[i];
        }
        delete[] _arreglo;
        _arreglo = nuevoArreglo;
        --_longitud;
    }
}

void Arreglo::imprimir(int inicio, int fin) {
    if (inicio < 0 || fin >= _longitud || inicio > fin) {
        std::cerr << "Rango inválido." << std::endl;
        return;
    }
    if (fin == -1) {
        fin = _longitud - 1;
    }
    for (int i = inicio; i <= fin; ++i) {
        std::cout << _arreglo[i] << " ";
    }
    std::cout << std::endl;
}

int Arreglo::buscarValor(char valor) {
    for (int i = 0; i < _longitud; ++i) {
        if (_arreglo[i] == valor) {
            return i;
        }
    }
    return -1;
}
