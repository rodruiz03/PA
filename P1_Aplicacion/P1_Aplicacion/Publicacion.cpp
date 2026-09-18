#include "Publicacion.h"
#include "iostream"

Publicacion::Publicacion() {
    cantidadDisponible = 0;
    cantidadPrestamo = 0;
    estado = "disponible";
}

Publicacion::~Publicacion() {
}

std::string Publicacion::getId() const {
    return id;
}

std::string Publicacion::getTitulo() const {
    return titulo;
}

std::string Publicacion::getMateria() const {
    return materia;
}

int Publicacion::getCantidadEjemplares() const {
    return cantidadEjemplares;
}

int Publicacion::getCantidadDisponible() const {
    return cantidadDisponible;
}

int Publicacion::getCantidadPrestamo() const {
    return cantidadPrestamo;
}

void Publicacion::prestarEjemplar() {
    if (cantidadDisponible > 0) {
        cantidadDisponible--;
        cantidadPrestamo++;
    }
}

void Publicacion::devolverEjemplar() {
    if (cantidadPrestamo > 0) {
        cantidadPrestamo--;
        cantidadDisponible++;
    }
}
