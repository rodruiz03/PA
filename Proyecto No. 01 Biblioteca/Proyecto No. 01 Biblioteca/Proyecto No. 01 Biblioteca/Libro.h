#pragma once
#ifndef LIBRO_H
#define LIBRO_H

#include "Publicacion.h"
#include <string>

class Libro : public Publicacion {
public:
    Libro() {}
    Libro(int id, std::string titulo, std::string autor, std::string editorial, std::string materia, int ejemplares, bool disponible) {
        this->autor = autor;
        this->editorial = editorial;
    }
    float calcularMulta(int diasRetraso);
    void crearLibro();
private:
    std::string autor;
    std::string editorial;
};

#endif