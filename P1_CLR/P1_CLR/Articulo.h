#pragma once
#include "Publicacion.h"

class Articulo : public Publicacion {
private:
    std::string arbitro;

public:
    Articulo(int id, const std::string& titulo, const std::string& materia, int cantidad, const std::string& estado, double precioMulta, const std::string& arbitro);
    std::string getArbitro() const;
};