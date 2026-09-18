#pragma once
#include "Cliente.h"
#include "Publicacion.h" // Asegúrate de que este include esté presente

class Especialista : public Cliente {
public:
    Especialista(const std::string& id, const std::string& nombre, const std::string& direccion);

    void mostrarDetalles() const override;
    void asignarPrecioPublicacion(Publicacion* publicacion, double precio);
};

