#include "pch.h"
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <limits>
#include <cstdlib>  // Para usar system("cls")

// Definición de la estructura Tarea
struct Tarea {
    std::string descripcion;
    int prioridad;

    Tarea(std::string desc, int prio) : descripcion(desc), prioridad(prio) {}
};

// Clase para gestionar la pila de tareas
class PilaTareas {
private:
    std::vector<Tarea> elementos;

public:
    void push(Tarea tarea) {
        elementos.push_back(tarea);
    }

    Tarea pop() {
        if (!elementos.empty()) {
            Tarea temp = elementos.back();
            elementos.pop_back();
            return temp;
        }
        else {
            throw std::out_of_range("Pila vacía");
        }
    }

    bool isEmpty() {
        return elementos.empty();
    }
};

// Clase para gestionar la cola de tareas
class ColaTareas {
public:
    std::deque<Tarea> elementos;  // Public for demonstration purposes

    void enqueue(Tarea tarea) {
        elementos.push_back(tarea);
    }

    Tarea dequeue() {
        if (!elementos.empty()) {
            Tarea temp = elementos.front();
            elementos.pop_front();
            return temp;
        }
        else {
            throw std::out_of_range("Cola vacía");
        }
    }

    bool isEmpty() {
        return elementos.empty();
    }
};

Tarea crear_tarea() {
    std::string descripcion;
    int prioridad;
    std::cout << "Ingrese la descripción de la tarea: ";
    std::getline(std::cin, descripcion);
    std::cout << "Ingrese la prioridad (1-3): ";
    std::cin >> prioridad;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Limpia el buffer de entrada de forma efectiva
    return Tarea(descripcion, prioridad);
}

void mostrar_menu() {
    std::cout << "1. Crear Tarea\n";
    std::cout << "2. Priorizar Tareas\n";
    std::cout << "3. Mostrar Lista de Tareas\n";
    std::cout << "4. Ejecutar Tarea\n";
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opción: ";
}

void limpiar_pantalla() {
    // Limpia la pantalla, funciona en la mayoría de sistemas operativos
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    PilaTareas pila_tareas;
    ColaTareas cola_tareas;
    int opcion;

    do {
        mostrar_menu();
        std::cin >> opcion;
        if (std::cin.fail()) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear out the buffer
            std::cout << "Opción no válida, intente nuevamente.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear out the buffer

        switch (opcion) {
        case 1: {
            Tarea tarea = crear_tarea();
            pila_tareas.push(tarea);
            break;
        }
        case 2: {
            while (!pila_tareas.isEmpty()) {
                Tarea tarea = pila_tareas.pop();
                std::cout << "Prioridad actual de '" << tarea.descripcion << "': " << tarea.prioridad << std::endl;
                std::cout << "Ingrese nueva prioridad (1-3): ";
                std::cin >> tarea.prioridad;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cola_tareas.enqueue(tarea);
            }
            break;
        }
        case 3: {
            if (cola_tareas.isEmpty()) {
                std::cout << "No hay tareas en la cola.\n";
            }
            else {
                for (const auto& tarea : cola_tareas.elementos) {
                    std::cout << "Tarea: " << tarea.descripcion << " - Prioridad: " << tarea.prioridad << std::endl;
                }
            }
            break;
        }
        case 4: {
            if (cola_tareas.isEmpty()) {
                std::cout << "No hay tareas para ejecutar.\n";
            }
            else {
                while (!cola_tareas.isEmpty()) {
                    Tarea tarea = cola_tareas.dequeue();
                    std::cout << "Ejecutando: " << tarea.descripcion << std::endl;
                }
            }
            break;
        }
        case 5:
            std::cout << "Saliendo del programa.\n";
            break;
        default:
            std::cout << "Opción no válida, intente nuevamente.\n";
        }
        if (opcion != 5) {
            std::cout << "\nPresione Enter para continuar...";
            std::cin.get();
            limpiar_pantalla();
        }
    } while (opcion != 5);

    return 0;
}