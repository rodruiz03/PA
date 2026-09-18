#include "pch.h"

#include "Publicacion.h"

Publicacion::Publicacion(int id, const std::string& titulo, const std::string& materia, int cantidad, const std::string& estado, double precioMulta)
    : id(id), titulo(titulo), materia(materia), cantidad(cantidad), estado(estado), precioMulta(precioMulta) {}

int Publicacion::getId() const {
    return id;
}

std::string Publicacion::getTitulo() const {
    return titulo;
}

std::string Publicacion::getMateria() const {
    return materia;
}

int Publicacion::getCantidad() const {
    return cantidad;
}

std::string Publicacion::getEstado() const {
    return estado;
}

double Publicacion::getPrecioMulta() const {
    return precioMulta;
}

