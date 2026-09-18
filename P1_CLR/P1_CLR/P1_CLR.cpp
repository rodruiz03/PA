#include "pch.h"
#include <iostream>
#include <string>
#include <limits>
#include <vector>

std::vector<Cliente*> clientes;
// Incluir las clases de tu proyecto aquí
#include "Cliente.h"
#include "Publicacion.h"
#include "Prestamo.h"
#include "Articulo.h"
#include "Especialista.h"
#include "Estudiante.h"
#include "Libro.h"
#include "Revista.h"

void mostrarMenu() {
    std::cout << "Sistema de Gestión de Biblioteca\n";
    std::cout << "--------------------------------\n";
    std::cout << "1. Indexar Cliente\n";
    std::cout << "2. Indexar Publicación\n";
    std::cout << "3. Realizar Préstamo\n";
    std::cout << "4. Prorrogar Préstamo\n";
    std::cout << "5. Procesar Devolución\n";
    std::cout << "6. Generar Reportes\n";
    std::cout << "7. Buscar Publicación por ID\n";
    std::cout << "8. Pasar Días\n";
    std::cout << "9. Salir\n";
    std::cout << "Seleccione una opción: ";
}

// Función stub para procesarOpcion, se llenará más adelante
void procesarOpcion(int opcion) {
    switch (opcion) {
    case 1:
        // Lógica para indexar cliente
        break;
    case 2:
        // Lógica para indexar publicación
        break;
        // ... Más casos según las opciones del menú
    case 9:
        std::cout << "Saliendo del sistema...\n";
        break;
    default:
        std::cout << "Opción no reconocida, por favor intente de nuevo.\n";
    }
}

int main() {
    int opcion = 0;
    do {
        mostrarMenu();
        while (!(std::cin >> opcion)) {
            std::cout << "Por favor, introduzca un número válido.\n";
            std::cin.clear(); // Limpia el estado de error de cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la entrada hasta el siguiente salto de línea
            mostrarMenu();
        }
        procesarOpcion(opcion);
    } while (opcion != 9);

    return 0;
}


void indexarCliente() {
    std::string identidad, nombre, direccion;
    int tipoCliente;
    std::cout << "Ingrese el tipo de cliente (1: Estudiante, 2: Especialista): ";
    std::cin >> tipoCliente;
    std::cin.ignore();
    std::cout << "Ingrese la identidad del cliente: ";
    std::cin >> identidad;
    std::cin.ignore();
    std::cout << "Ingrese el nombre del cliente: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese la dirección del cliente: ";
    std::getline(std::cin, direccion);

    Cliente* nuevoCliente = nullptr;
    if (tipoCliente == 1) {
        nuevoCliente = new Estudiante(identidad, nombre, direccion);
    }
    else if (tipoCliente == 2) {
        nuevoCliente = new Especialista(identidad, nombre, direccion);
    }

    if (nuevoCliente != nullptr) {
        clientes.push_back(nuevoCliente);
        std::cout << "Cliente agregado exitosamente.\n";
    }
    else {
        std::cout << "Tipo de cliente no válido.\n";
    }
}



void indexarPublicacion() {
    int tipoPublicacion;
    std::cout << "Seleccione el tipo de publicación (1: Libro, 2: Revista, 3: Artículo): ";
    std::cin >> tipoPublicacion;
    std::cin.ignore();

    int id, cantidad;
    std::string titulo, materia, estado, autor, editorial, arbitro;
    int anio, numero;
    std::cout << "Ingrese el ID de la publicación (6 cifras): ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Ingrese el título de la publicación: ";
    std::getline(std::cin, titulo);
    std::cout << "Ingrese la materia de la publicación: ";
    std::getline(std::cin, materia);
    std::cout << "Ingrese el estado de la publicación (disponible/agotado): ";
    std::getline(std::cin, estado);
    std::cout << "Ingrese la cantidad de ejemplares: ";
    std::cin >> cantidad;
    std::cin.ignore();

    Publicacion* nuevaPublicacion = nullptr;

    switch (tipoPublicacion) {
    case 1:  // Libro
        std::cout << "Ingrese el autor del libro: ";
        std::getline(std::cin, autor);
        std::cout << "Ingrese la editorial del libro: ";
        std::getline(std::cin, editorial);
        nuevaPublicacion = new Libro(id, titulo, autor, editorial, materia, cantidad, estado);
        break;
    case 2:  // Revista
        std::cout << "Ingrese el año de la revista: ";
        std::cin >> anio;
        std::cout << "Ingrese el número de la revista: ";
        std::cin >> numero;
        nuevaPublicacion = new Revista(id, titulo, anio, numero, materia, cantidad, estado);
        break;
    case 3:  // Artículo
        std::cout << "Ingrese el árbitro del artículo: ";
        std::cin.ignore();
        std::getline(std::cin, arbitro);
        nuevaPublicacion = new Articulo(id, titulo, arbitro, materia, cantidad, estado);
        break;
    }

    if (nuevaPublicacion != nullptr) {
        publicaciones.push_back(nuevaPublicacion);
        std::cout << "Publicación agregada exitosamente.\n";
    }
    else {
        std::cout << "Tipo de publicación no válido.\n";
    }
}


void realizarPrestamo() {
    // Código para procesar un nuevo préstamo
}

// Implementar el resto de las funciones según sea necesario...

// No olvides definir pasarDias, que podría involucrar actualizar las fechas de préstamo y calcular multas

void pasarDias() {
    int dias;
    std::cout << "Ingrese el número de días a avanzar: ";
    std::cin >> dias;

    // Actualiza las fechas de préstamo y calcula multas según sea necesario
}

