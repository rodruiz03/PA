#pragma once
#ifndef REVISTA_H
#define REVISTA_H

#include "Publicacion.h"
#include <string>

class Revista : public Publicacion {
public:
    Revista() {}
    Revista(int id, std::string titulo, int año, int numero, std::string materia, int ejemplares, bool disponible) {
        this->año = año;
        this->numero = numero;
    }
    float calcularMulta(int diasRetraso);
    void crearRevista();

private:
    int año;
    int numero;
};

#endif