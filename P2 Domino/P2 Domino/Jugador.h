#pragma once
#include <string>
#include <vector>
#include "Ficha.h"

class Jugador {
public:
    std::string nombre;
    std::vector<Ficha> fichas;
    int puntos;

    Jugador(const std::string& nombre);

    void MostrarFichas() const;
};
