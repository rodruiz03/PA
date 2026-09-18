#include "pch.h"
#include "Ficha.h"

Ficha::Ficha(int c1, int c2) : cara1(c1), cara2(c2) {}

void Ficha::Mostrar() const {
    std::cout << "[" << cara1 << "|" << cara2 << "]";
}

void Ficha::MostrarReversa() const {
    std::cout << "[" << cara2 << "|" << cara1 << "]";
}

bool Ficha::EsCompatible(int valor) const {
    return (cara1 == valor || cara2 == valor);
}

void Ficha::Girar() {
    std::swap(cara1, cara2);
}
