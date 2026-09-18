#pragma once
#include "Publicacion.h"

class Articulo : public Publicacion {
    std::string arbitro;

public:
    // Actualiza el constructor para incluir el año
    Articulo(int id, const std::string& titulo, const std::string& arbitro,
        const std::string& materia, int cantidad,
        const std::string& estado, double precio, int anio);

    void mostrarDetalles() const override; // Implementación propia para mostrar los detalles del artículo.
    // Otros métodos específicos para Articulo...
};