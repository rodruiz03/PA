#pragma once
#include <iostream>

class Ficha {
public:
    int cara1;
    int cara2;

    Ficha(int c1, int c2);

    void Mostrar() const;
    void MostrarReversa() const;
    bool EsCompatible(int valor) const;
    void Girar();
};
