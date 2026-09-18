#pragma once
#include "Publicacion.h"
#include <string>
#include <iostream>

class Cliente;  // Declaración anticipada

class Prestamo {
private:
    Cliente* cliente;
    Publicacion* publicacion;
    std::string fechaPrestamo;
    std::string fechaDevolucion;
    bool devuelto;

public:
    Prestamo(Cliente* cliente, Publicacion* publicacion, const std::string& fechaPrestamo);
    virtual ~Prestamo() = default;

    void realizarDevolucion(const std::string& fechaDevolucion);

    // Métodos getters y setters
    bool estaDevuelto() const {
        return devuelto;
    }

    // Otros métodos según sea necesario
};
