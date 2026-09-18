#include "pch.h"
#include <iostream>
#include <limits>
#include "Ficha.h"
#include "Jugador.h"
#include "Juego.h"

int main() {
    int num_jugadores;
    int puntos_a_ganar;

    // Validar entrada del número de jugadores
    while (true) {
        std::cout << "Ingrese el número de jugadores (2-4): ";
        std::cin >> num_jugadores;

        if (std::cin.fail() || num_jugadores < 2 || num_jugadores > 4) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Número de jugadores inválido. Ingrese un número entre 2 y 4.\n";
        }
        else {
            break;
        }
    }

    // Validar entrada de la cantidad de puntos para ganar
    while (true) {
        std::cout << "Ingrese la cantidad de puntos para ganar (mínimo 25): ";
        std::cin >> puntos_a_ganar;

        if (std::cin.fail() || puntos_a_ganar < 25) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Cantidad de puntos inválida. Ingrese un valor mayor o igual a 25.\n";
        }
        else {
            break;
        }
    }

    Juego juego(num_jugadores, puntos_a_ganar);
    juego.Jugar();

    return 0;
}
