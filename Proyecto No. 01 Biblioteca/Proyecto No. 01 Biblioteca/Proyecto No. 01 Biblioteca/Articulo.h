#pragma once
#ifndef ARTICULO_H
#define ARTICULO_H

#include "Publicacion.h"
#include <string>

class Articulo : public Publicacion {
public:
    Articulo() {}
    Articulo(int id, std::string titulo, std::string arbitro, std::string materia, int ejemplares, bool disponible) {
        this->arbitro = arbitro;
    }
    float calcularMulta(int diasRetraso);
    void crearArticulo();

private:
    std::string arbitro;
};

#endif