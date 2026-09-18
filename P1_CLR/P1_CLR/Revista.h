#pragma once
#include "Publicacion.h"

class Revista : public Publicacion {
private:
    int ano;
    int numero;

public:
    Revista(int id, const std::string& titulo, const std::string& materia, int cantidad, const std::string& estado, double precioMulta, int ano, int numero);
    int getAno() const;
    int getNumero() const;
};
