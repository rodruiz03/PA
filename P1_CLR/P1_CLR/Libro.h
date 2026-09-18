#pragma once
#include "Publicacion.h"

class Libro : public Publicacion {
private:
    std::string autor;
    std::string editorial;

public:
    Libro(int id, const std::string& titulo, const std::string& materia, int cantidad, const std::string& estado, double precioMulta, const std::string& autor, const std::string& editorial);
    std::string getAutor() const;
    std::string getEditorial() const;
};