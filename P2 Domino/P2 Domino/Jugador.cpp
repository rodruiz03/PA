#include "pch.h"
#include "Jugador.h"

Jugador::Jugador(const std::string& nombre) : nombre(nombre), puntos(0) {}

void Jugador::MostrarFichas() const {
    std::cout << nombre << "'s Fichas: ";
    for (size_t i = 0; i < fichas.size(); ++i) {
        std::cout << i << ": ";
        fichas[i].Mostrar();
        std::cout << " ";
    }
    std::cout << std::endl;
}
