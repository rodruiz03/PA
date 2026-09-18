#include "pch.h"
#include "Libro.h"

Libro::Libro(int id, const std::string& titulo, const std::string& autor,
    const std::string& editorial, const std::string& materia,
    int cantidad, const std::string& estado, double precio, int anio)
    : Publicacion(id, titulo, materia, cantidad, estado, precio, anio),
    autor(autor),
    editorial(editorial) {
    // Aquí puede ir lógica adicional para el constructor de Libro, si es necesario.
}

void Libro::mostrarDetalles() const {
    // Mostrar detalles del libro, incluyendo los de la clase base Publicacion.
}
