#pragma once
#include "Cliente.h"

class Estudiante : public Cliente {
public:
    Estudiante(const std::string& identidad, const std::string& nombre, const std::string& direccion)
        : Cliente(identidad, nombre, direccion) {}

    virtual ~Estudiante() = default;

    // Métodos específicos de Estudiante
};