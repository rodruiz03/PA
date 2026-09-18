#pragma once
#include "Publicacion.h"

class Libro : public Publicacion {
    std::string autor;
    std::string editorial;

public:
    // Actualiza el constructor para incluir el año
    // Asegúrate de que el constructor acepte el nuevo parámetro 'anio'.
    Libro(int id, const std::string& titulo, const std::string& autor,
        const std::string& editorial, const std::string& materia,
        int cantidad, const std::string& estado, double precio, int anio);

    void mostrarDetalles() const override; // Implementación propia para mostrar los detalles del libro.
    // Otros métodos específicos para Libro...
    std::string getAutor() const { return autor; }
    std::string getEditorial() const { return editorial; }
};