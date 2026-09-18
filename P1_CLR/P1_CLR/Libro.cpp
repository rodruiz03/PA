#include "pch.h"  // Asegúrate de que esta es la primera línea si usas PCH
#include "Libro.h"

Libro::Libro(int id, const std::string& titulo, const std::string& materia, int cantidad, const std::string& estado, double precioMulta, const std::string& autor, const std::string& editorial)
    : Publicacion(id, titulo, materia, cantidad, estado, precioMulta), autor(autor), editorial(editorial) {}

std::string Libro::getAutor() const {
    return autor;
}

std::string Libro::getEditorial() const {
    return editorial;
}