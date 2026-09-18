#include "iostream"
#include "Publicacion.h"
#include "Libro.h"

Publicacion::~Publicacion() {}

int Publicacion::getId() const {
    return id;
}

std::string Publicacion::getTitulo() const {
    return titulo;
}

std::string Publicacion::getMateria() const {
    return materia;
}

int Publicacion::getEjemplares() const {
    return ejemplares;
}

bool Publicacion::estaDisponible() const {
    return disponible;
}

char Publicacion::ingresarPublicacion(char tipoPublicacion) {
    std::cout << "** Ingresar una nueva publicacion **\n" << std::endl;
    std::cout << "Ingrese el tipo de publicacion: Libro, Revista o Articulo (L, R, A)" << std::endl;
    std::cin >> tipoPublicacion;
    tipoPublicacion = toupper(tipoPublicacion);
    /*while (tipoPublicacion != 'L' || tipoPublicacion != 'R' || tipoPublicacion != 'A') {
        std::cout << "El valor ingresado es invalido, intentelo de nuevo (L, R, A): " << std::endl;
        std::cin >> tipoPublicacion;
        tipoPublicacion = toupper(tipoPublicacion);
    }*/
    return tipoPublicacion;
}