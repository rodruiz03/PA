
#include "pch.h"
#include <iostream>
#include "Cancion.h"
#include "ListaDeCanciones.h"
#include "BibliotecaMusical.h"

int main() {
    BibliotecaMusical biblioteca;
    int opcion = 0;
    std::string nombre, artista, album, genero, linkPortada, nombreLista, fechaCreacion;
    double duracion;
    int id, cantReproducciones, idLista;

    do {
        std::cout << "\n*** Biblioteca Musical ***\n";
        std::cout << "1. Agregar Lista de Canciones\n";
        std::cout << "2. Agregar Canción a una Lista\n";
        std::cout << "3. Mostrar Listas\n";
        std::cout << "4. Mostrar Canciones de una Lista\n";
        std::cout << "5. Buscar Canción por Nombre, Artista o Género\n";
        std::cout << "6. Seleccionar y Mostrar Información de una Canción\n";
        std::cout << "7. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "Ingrese el ID de la lista: ";
            std::cin >> idLista;
            std::cin.ignore();
            std::cout << "Ingrese el nombre de la lista: ";
            std::getline(std::cin, nombreLista);
            std::cout << "Ingrese la fecha de creación (DD/MM/AAAA): ";
            std::getline(std::cin, fechaCreacion);
            biblioteca.agregarLista(ListaDeCanciones(idLista, nombreLista, fechaCreacion));
            break;
        case 2:
            std::cout << "Ingrese el ID de la canción: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Ingrese el nombre de la canción: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingrese el artista: ";
            std::getline(std::cin, artista);
            std::cout << "Ingrese la duración (en minutos): ";
            std::cin >> duracion;
            std::cin.ignore();
            std::cout << "Ingrese el álbum: ";
            std::getline(std::cin, album);
            std::cout << "Ingrese el género: ";
            std::getline(std::cin, genero);
            std::cout << "Ingrese el link de la portada: ";
            std::getline(std::cin, linkPortada);
            std::cout << "Ingrese el número de reproducciones: ";
            std::cin >> cantReproducciones;
            std::cout << "Ingrese el ID de la lista donde agregar: ";
            std::cin >> idLista;
            biblioteca.agregarCancionALista(id, idLista, Cancion(id, nombre, artista, duracion, album, genero, linkPortada, cantReproducciones));
            break;
        case 3:
            biblioteca.mostrarListas();
            break;
        case 4:
            std::cout << "Ingrese el ID de la lista para mostrar canciones: ";
            std::cin >> idLista;
            biblioteca.mostrarCancionesDeLista(idLista);
            break;
        case 5:
            std::cout << "Ingrese el criterio de búsqueda (nombre, artista o género): ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            biblioteca.buscarCancionEnListas(nombre);
            break;
        case 6:
            std::cout << "Seleccione una lista para ver sus canciones:\n";
            biblioteca.mostrarListas();
            std::cout << "Ingrese el ID de la lista: ";
            std::cin >> idLista;
            biblioteca.mostrarCancionesDeLista(idLista);
            std::cout << "Ingrese el ID de la canción para mostrar información: ";
            std::cin >> id;
            // Llamada a una función ficticia que asumimos existe para mostrar detalles de una canción
            biblioteca.mostrarInformacionCancion(idLista, id);
            break;
        case 7:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opción no válida, intente de nuevo.\n";
        }
    } while (opcion != 7);

    return 0;
}
