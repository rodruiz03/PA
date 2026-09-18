#include "Revista.h"

Revista::Revista() : Publicacion() {
}

Revista::~Revista() {
}

void Revista::llenarDatos() {
    Publicacion::llenarDatos();
    std::cout << "Ingrese el año de la revista: ";
    std::cin >> anio;
    std::cout << "Ingrese el número de la revista: ";
    std::cin >> numero;
}

int Revista::getAnio() const {
    return anio;
}

int Revista::getNumero() const {
    return numero;
}

