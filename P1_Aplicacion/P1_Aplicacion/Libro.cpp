#include "Libro.h"

Libro::Libro() : Publicacion() {
}

Libro::~Libro() {
}

void Libro::llenarDatos() {
    Publicacion::llenarDatos();
    std::cout << "Ingrese el autor del libro: ";
    std::cin.ignore();
    std::getline(std::cin, autor);
    std::cout << "Ingrese la editorial del libro: ";
    std::getline(std::cin, editorial);
}

std::string Libro::getAutor() const {
    return autor;
}

std::string Libro::getEditorial() const {
    return editorial;
}
