#pragma once
#include "Cliente.h"

class Especialista : public Cliente {
public:
    Especialista(const std::string& identidad, const std::string& nombre, const std::string& direccion)
        : Cliente(identidad, nombre, direccion) {}

    virtual ~Especialista() = default;

    void asignarPreciosAPublicaciones();  // Implementación pendiente
};