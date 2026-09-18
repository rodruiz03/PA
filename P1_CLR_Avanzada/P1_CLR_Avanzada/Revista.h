#pragma once
#include "Publicacion.h"

class Revista : public Publicacion {
    int anio;
    int numero;

public:
    // Actualiza el constructor para incluir el año
    Revista(int id, const std::string& titulo, int anio, int numero,
        const std::string& materia, int cantidad,
        const std::string& estado, double precio);

    void mostrarDetalles() const override; // Implementación propia para mostrar los detalles de la revista.
    // Otros métodos específicos para Revista...
};