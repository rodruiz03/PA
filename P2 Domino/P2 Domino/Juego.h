#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include "Jugador.h"
#include "Ficha.h"

class Juego {
private:
    std::vector<Jugador> jugadores;
    std::vector<Ficha> pozo;
    std::vector<Ficha> tablero;
    int puntos_a_ganar;

    void InicializarFichas();
    void DistribuirFichas();
    Jugador& SeleccionarJugadorInicial();
    bool ColocarFicha(Jugador& jugador, size_t index);

public:
    Juego(int num_jugadores, int puntos);

    void MostrarTablero() const;
    void MostrarPuntuacion() const;
    void Jugar();
    void CalcularPuntos();
    bool VerificarCondicionVictoria() const;
};
