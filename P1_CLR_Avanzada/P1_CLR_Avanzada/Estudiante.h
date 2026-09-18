#pragma once
#include "Cliente.h"

class Estudiante : public Cliente {
public:
    Estudiante(const std::string& id, const std::string& nombre, const std::string& direccion);

    void mostrarDetalles() const override;
};
