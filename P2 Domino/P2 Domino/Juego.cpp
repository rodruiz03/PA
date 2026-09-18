#include "pch.h"
#include "Juego.h"

Juego::Juego(int num_jugadores, int puntos) : puntos_a_ganar(puntos) {
    for (int i = 0; i < num_jugadores; i++) {
        std::string nombre;
        std::cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        std::cin >> nombre;
        jugadores.emplace_back(nombre);
    }
    InicializarFichas();
    DistribuirFichas();
}

void Juego::InicializarFichas() {
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            pozo.emplace_back(i, j);
        }
    }
    std::shuffle(pozo.begin(), pozo.end(), std::mt19937{ std::random_device{}() });
}

void Juego::DistribuirFichas() {
    int fichas_por_jugador = jugadores.size() == 2 ? 7 : 5;
    for (auto& jugador : jugadores) {
        for (int i = 0; i < fichas_por_jugador; i++) {
            jugador.fichas.push_back(pozo.back());
            pozo.pop_back();
        }
    }
}

Jugador& Juego::SeleccionarJugadorInicial() {
    Jugador* inicial = nullptr;
    Ficha ficha_inicial(-1, -1);

    for (auto& jugador : jugadores) {
        for (auto& ficha : jugador.fichas) {
            if (ficha.cara1 == ficha.cara2 && ficha.cara1 > ficha_inicial.cara1) {
                inicial = &jugador;
                ficha_inicial = ficha;
            }
        }
    }

    if (!inicial) {
        for (auto& jugador : jugadores) {
            for (auto& ficha : jugador.fichas) {
                int valor_ficha = ficha.cara1 + ficha.cara2;
                int valor_ficha_inicial = ficha_inicial.cara1 + ficha_inicial.cara2;
                if (valor_ficha > valor_ficha_inicial) {
                    inicial = &jugador;
                    ficha_inicial = ficha;
                }
            }
        }
    }

    return *inicial;
}

bool Juego::ColocarFicha(Jugador& jugador, size_t index) {
    Ficha ficha = jugador.fichas[index];
    if (tablero.empty()) {
        // Si el tablero está vacío, colocamos la ficha directamente
        tablero.push_back(ficha);
        jugador.fichas.erase(jugador.fichas.begin() + index);
        return true;
    }
    else {
        int izquierda = tablero.front().cara1;  // Extremo izquierdo del tablero
        int derecha = tablero.back().cara2;     // Extremo derecho del tablero

        // Verificar si se puede colocar en el lado izquierdo del tablero
        if (ficha.cara1 == izquierda) {
            ficha.Girar();  // Girar la ficha para que coincida
            tablero.insert(tablero.begin(), ficha);  // Insertar al principio del tablero
            jugador.fichas.erase(jugador.fichas.begin() + index);  // Eliminar de la mano del jugador
            return true;
        }
        else if (ficha.cara2 == izquierda) {
            tablero.insert(tablero.begin(), ficha);  // Insertar al principio del tablero
            jugador.fichas.erase(jugador.fichas.begin() + index);  // Eliminar de la mano del jugador
            return true;
        }

        // Verificar si se puede colocar en el lado derecho del tablero
        if (ficha.cara1 == derecha) {
            tablero.push_back(ficha);  // Insertar al final del tablero
            jugador.fichas.erase(jugador.fichas.begin() + index);  // Eliminar de la mano del jugador
            return true;
        }
        else if (ficha.cara2 == derecha) {
            ficha.Girar();  // Girar la ficha para que coincida
            tablero.push_back(ficha);  // Insertar al final del tablero
            jugador.fichas.erase(jugador.fichas.begin() + index);  // Eliminar de la mano del jugador
            return true;
        }
    }
    return false;  // No se pudo colocar la ficha
}

void Juego::MostrarTablero() const {
    std::cout << std::endl; // Espacio entre fichas del jugador y el tablero
    std::cout << "Tablero: ";
    for (const auto& ficha : tablero) {
        ficha.Mostrar();
        std::cout << " ";
    }
    std::cout << std::endl;
}

void Juego::MostrarPuntuacion() const {
    std::cout << std::endl; // Espacio antes de mostrar puntuaciones
    std::cout << "Puntuación: ";
    for (const auto& jugador : jugadores) {
        std::cout << jugador.nombre << ": " << jugador.puntos << " puntos. ";
    }
    std::cout << std::endl;
}

void Juego::Jugar() {
    if (puntos_a_ganar < 25) {
        std::cout << "La cantidad de puntos para ganar debe ser al menos 25.\n";
        return;
    }

    Jugador& inicial = SeleccionarJugadorInicial();
    std::cout << "El jugador inicial es: " << inicial.nombre << std::endl;

    // Esperar a que el usuario presione Enter para comenzar el juego
    std::cout << "Presione Enter para comenzar el juego..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    // Usar una ficha del pozo para iniciar el tablero
    Ficha ficha_inicial = pozo.back();
    pozo.pop_back();
    tablero.push_back(ficha_inicial);

    MostrarTablero();
    MostrarPuntuacion();

    size_t turno_actual = &inicial - &jugadores[0];
    int turnos_sin_jugada = 0;  // Contador de turnos sin jugadas válidas

    while (true) { // Ciclo principal del juego
        Jugador& jugador = jugadores[turno_actual];
        system("CLS");
        std::cout << "\nTurno de " << jugador.nombre << "\n";
        jugador.MostrarFichas();
        MostrarTablero();
        MostrarPuntuacion();

        bool jugada_valida = false;
        while (!jugada_valida) {
            std::cout << "Seleccione una ficha para jugar (o -1 para tomar del pozo): ";
            int seleccion;

            // Validar la entrada del usuario
            while (!(std::cin >> seleccion)) {
                std::cin.clear();  // Limpia el error de entrada
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignora la entrada hasta la nueva línea
                std::cout << "Entrada inválida. Por favor ingrese un número: ";
            }

            if (seleccion == -1) {
                if (pozo.empty()) {
                    std::cout << "El pozo está vacío. Pierdes el turno.\n";
                    break;
                }
                else {
                    Ficha nueva_ficha = pozo.back();
                    pozo.pop_back();
                    jugador.fichas.push_back(nueva_ficha);
                    std::cout << "Nueva ficha tomada del pozo: ";
                    nueva_ficha.Mostrar();
                    std::cout << std::endl;
                    // Mostrar las fichas nuevamente después de tomar una nueva ficha del pozo
                    jugador.MostrarFichas();
                }
            }
            else if (seleccion >= 0 && seleccion < jugador.fichas.size()) {
                if (ColocarFicha(jugador, seleccion)) {
                    jugada_valida = true;
                    turnos_sin_jugada = 0;  // Resetear el contador de turnos sin jugadas válidas
                }
                else {
                    std::cout << "Ficha inválida. Intente de nuevo.\n";
                }
            }
            else {
                std::cout << "Selección inválida. Intente de nuevo.\n";
            }
        }

        // Comprobación de fin de ronda
        if (jugador.fichas.empty()) {
            std::cout << jugador.nombre << " se ha quedado sin fichas. La ronda ha terminado.\n";
            CalcularPuntos();
            if (VerificarCondicionVictoria()) {
                // Mostrar el mensaje de victoria
                std::cout << "¡" << jugador.nombre << " ha ganado el juego con " << jugador.puntos << " puntos!\n";
                break;
            }
            else {
                // Mostrar el mensaje de victoria para el jugador que se quedó sin fichas
                std::cout << "¡" << jugador.nombre << " ha ganado la ronda con " << jugador.puntos << " puntos!\n";
            }
            break; // Termina el juego cuando un jugador se queda sin fichas
        }

        turno_actual = (turno_actual + 1) % jugadores.size();
        if (jugada_valida) {
            turnos_sin_jugada = 0;  // Resetear si hubo una jugada válida
        }
        else {
            turnos_sin_jugada++;
            if (turnos_sin_jugada >= jugadores.size()) {
                std::cout << "Ningún jugador puede realizar una jugada. La ronda ha terminado.\n";
                CalcularPuntos();
                if (VerificarCondicionVictoria()) {
                    break;
                }
            }
        }
    }
}

void Juego::CalcularPuntos() {
    for (auto& jugador : jugadores) {
        int puntos_ronda = 0;
        for (const auto& ficha : jugador.fichas) {
            puntos_ronda += ficha.cara1 + ficha.cara2;
        }
        jugador.puntos += puntos_ronda;
    }

    MostrarPuntuacion();
}

bool Juego::VerificarCondicionVictoria() const {
    // Encuentra al jugador con la menor puntuación
    const Jugador* ganador = &jugadores[0];
    for (const auto& jugador : jugadores) {
        if (jugador.puntos < ganador->puntos) {
            ganador = &jugador;
        }
    }

    // Si cualquier jugador ha alcanzado o superado la cantidad de puntos a ganar, termina el juego
    if (ganador->puntos >= puntos_a_ganar) {
        std::cout << "¡ " << ganador->nombre << " ha ganado el juego con " << ganador->puntos << " puntos!\n";
        return true;
    }

    return false;
}
