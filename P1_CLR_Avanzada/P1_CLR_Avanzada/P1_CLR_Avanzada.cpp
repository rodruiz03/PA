#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

// Incluir las declaraciones de clases

#include "Cliente.h"
#include "Especialista.h"
#include "Estudiante.h"
#include "Articulo.h"
#include "Libro.h"
#include "Revista.h"
#include "Publicacion.h"
#include "Global.h"
#include "Tiempo.h"


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

    if (tipoCliente == 1) {
        estudiantes.push_back(std::make_unique<Estudiante>(identidad, nombre, direccion));
        std::cout << "Estudiante agregado exitosamente.\n";
    }
    else if (tipoCliente == 2) {
        especialistas.push_back(std::make_unique<Especialista>(identidad, nombre, direccion));
        std::cout << "Especialista agregado exitosamente.\n";
    }
    else {
        std::cout << "Tipo de cliente no válido.\n";
    }
}

bool existeEspecialista() {
    return !especialistas.empty(); // Verifica si la lista de especialistas está vacía
}

void indexarPublicacion() {

    if (!existeEspecialista()) {
        std::cout << "No se pueden añadir publicaciones sin un especialista en el sistema.\n";
        return;
    }

    std::string identidadEspecialista;
    std::cout << "Ingrese la identidad del especialista que indexará la publicación: ";
    std::cin >> identidadEspecialista;
    std::cin.ignore();

    auto especialista = std::find_if(especialistas.begin(), especialistas.end(),
        [&identidadEspecialista](const auto& esp) {
            return esp->getIdentidad() == identidadEspecialista;
        });

    if (especialista == especialistas.end()) {
        std::cout << "No se ha encontrado un especialista con esa identidad.\n";
        return;
    }


    int tipoPublicacion;
    std::cout << "Seleccione el tipo de publicación (1: Libro, 2: Revista, 3: Artículo): ";
    std::cin >> tipoPublicacion;
    std::cin.ignore();

    int id, cantidad, anio, numero;
    double precio;
    std::string titulo, autor, editorial, materia, estado, arbitro;

    std::cout << "Ingrese el ID de la publicación: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Ingrese el título de la publicación: ";
    std::getline(std::cin, titulo);
    std::cout << "Ingrese la materia de la publicación: ";
    std::getline(std::cin, materia);
    std::cout << "Ingrese la cantidad de ejemplares: ";
    std::cin >> cantidad;
    std::cin.ignore();
    std::cout << "Ingrese el estado de la publicación (disponible/agotado): ";
    std::getline(std::cin, estado);
    std::cout << "Ingrese el precio de la publicación: ";
    std::cin >> precio;
    std::cin.ignore();
    std::cout << "Ingrese el año de la publicación: ";
    std::cin >> anio;
    std::cin.ignore();

    switch (tipoPublicacion) {
    case 1:  // Libro
        std::cout << "Ingrese el autor del libro: ";
        std::getline(std::cin, autor);
        std::cout << "Ingrese la editorial del libro: ";
        std::getline(std::cin, editorial);
        libros.push_back(std::make_unique<Libro>(id, titulo, autor, editorial, materia, cantidad, estado, precio, anio));
        break;
    case 2:  // Revista
        std::cout << "Ingrese el año de la revista: ";
        std::cin >> anio;
        std::cin.ignore();
        std::cout << "Ingrese el número de la revista: ";
        std::cin >> numero;
        std::cin.ignore();
        revistas.push_back(std::make_unique<Revista>(id, titulo, anio, numero, materia, cantidad, estado, precio));
        break;
    case 3:  // Artículo
        std::cout << "Ingrese el árbitro del artículo: ";
        std::getline(std::cin, arbitro);
        articulos.push_back(std::make_unique<Articulo>(id, titulo, arbitro, materia, cantidad, estado, precio, anio));
        break;
    default:
        std::cout << "Tipo de publicación no válido.\n";
        return;
    }

    std::cout << "Publicación agregada exitosamente con el precio de: " << precio << ".\n";
}

// Declaración global de la instancia de tiempo
Tiempo sistemaTiempo;

void pasarDias() {
    int dias;
    std::cout << "Ingrese el número de días que desea avanzar: ";
    while (std::cin >> dias && dias > 0) {
        sistemaTiempo.avanzarDias(dias);
        std::cout << "La fecha actual es: " << sistemaTiempo.obtenerFechaActual() << std::endl;
        std::cout << "Si desea avanzar mas dias digitalice cuantos si no (0 para salir e ir al menu principal): ";
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


extern Tiempo sistemaTiempo; // Asegúrate de que 'sistemaTiempo' está definido en otro archivo si es necesario.

void realizarPrestamo() {
    std::string idCliente;
    int idPublicacion;
    std::cout << "Ingrese la identidad del cliente: ";
    std::cin >> idCliente;
    std::cout << "Ingrese el ID de la publicación: ";
    std::cin >> idPublicacion;

    auto cliente = buscarClientePorId(idCliente);
    auto publicacion = buscarPublicacionPorId(idPublicacion);

    if (cliente && publicacion && publicacion->getCopiasDisponibles() > 0) {
        if (cliente->getPrestamosActivos() < 5) {
            auto nuevoPrestamo = std::make_shared<Prestamo>(cliente, publicacion, sistemaTiempo.obtenerFechaActual());
            prestamos.push_back(std::move(nuevoPrestamo));
            publicacion->prestarCopia();
            cliente->incrementarPrestamos(); // Incrementamos el contador de préstamos activos
            std::cout << "Préstamo realizado con éxito." << std::endl;
        }
        else {
            std::cout << "El cliente ha alcanzado el límite máximo de préstamos activos." << std::endl;
        }
    }
    else {
        std::cout << "Préstamo no se puede realizar. Cliente o Publicación no encontrados, o no hay copias disponibles." << std::endl;
    }
}


void prorrogarPrestamo() {
    std::string idCliente;
    int idPublicacion;
    std::cout << "Ingrese la identidad del cliente para la prórroga: ";
    std::cin >> idCliente;
    std::cout << "Ingrese el ID de la publicación para la prórroga: ";
    std::cin >> idPublicacion;

    for (auto& prestamo : prestamos) {
        if (prestamo->getCliente()->getIdentidad() == idCliente &&
            prestamo->getPublicacion()->getId() == idPublicacion &&
            !prestamo->esDevuelto() && !prestamo->esProrrogado()) {

            prestamo->prorrogar();  // No necesitamos la nueva fecha aquí
            std::cout << "Préstamo prorrogado hasta: " << prestamo->getFechaDevolucion() << std::endl;
            return;

        }
        else if (prestamo->esProrrogado()) {
            std::cout << "El préstamo ya ha sido prorrogado y no puede prorrogarse de nuevo." << std::endl;
            return;
        }
    }
    std::cout << "Préstamo no encontrado o ya devuelto." << std::endl;
}




void procesarDevolucion() {
    std::string idCliente;
    int idPublicacion;
    std::cout << "Ingrese la identidad del cliente que devuelve: ";
    std::cin >> idCliente;
    std::cout << "Ingrese el ID de la publicación que se devuelve: ";
    std::cin >> idPublicacion;

    for (auto& prestamo : prestamos) {
        if (prestamo->getCliente()->getIdentidad() == idCliente &&
            prestamo->getPublicacion()->getId() == idPublicacion &&
            !prestamo->esDevuelto()) {

            prestamo->realizarDevolucion(sistemaTiempo.obtenerFechaActual()); // Marcamos el préstamo como devuelto
            prestamo->getPublicacion()->devolverCopia(); // Incrementamos las copias disponibles
            prestamo->getCliente()->decrementarPrestamos(); // Decrementamos los préstamos activos del cliente
            std::cout << "Devolución procesada correctamente." << std::endl;
            return;

        }
    }
    std::cout << "No se encontró un préstamo activo con esos datos." << std::endl;
}

void buscarPublicacionPorCriterios() {
    int subopcion;
    std::cout << "Buscar Publicación Por:\n";
    std::cout << "1. Año\n";
    std::cout << "2. ID\n";
    std::cout << "3. Editorial\n";
    std::cout << "4. Autor\n";
    std::cout << "Seleccione una opción: ";
    std::cin >> subopcion;
    std::cin.ignore();

    int anio;
    int id;
    std::string editorial;
    std::string autor;

    switch (subopcion) {
    case 1:
        std::cout << "Ingrese el año: ";
        std::cin >> anio;
        buscarPorAnio(anio);
        break;
    case 2:
        std::cout << "Ingrese el ID: ";
        std::cin >> id;
        buscarPorID(id);
        break;
    case 3:
        std::cout << "Ingrese la editorial: ";
        std::getline(std::cin, editorial);
        buscarPorEditorial(editorial);
        break;
    case 4:
        std::cout << "Ingrese el autor: ";
        std::getline(std::cin, autor);
        buscarPorAutor(autor);
        break;
    default:
        std::cout << "Opción no válida, por favor intente de nuevo.\n";
    }
}
// Otros prototipos de funciones

void imprimirReportes() {

}

void mostrarMenu() {
    int opcion;
    do {
        std::cout << "Fecha actual: " << sistemaTiempo.obtenerFechaActual() << std::endl;
        std::cout << "Sistema de Gestión de Biblioteca\n";
        std::cout << "--------------------------------\n";
        std::cout << "1. Indexar Cliente\n";
        std::cout << "2. Indexar Publicación\n";
        std::cout << "3. Realizar Préstamo\n";
        std::cout << "4. Prorrogar Préstamo\n";
        std::cout << "5. Procesar Devolución\n";
        std::cout << "6. Generar Reportes\n";
        std::cout << "7. Buscar Publicación\n";
        std::cout << "8. Pasar Días\n";
        std::cout << "9. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:
            indexarCliente();
            break;
        case 2:
            indexarPublicacion();
            break;
        case 3:
            realizarPrestamo();  // Opción para realizar un préstamo
            break;
        case 4:
            prorrogarPrestamo();
            break;
        case 5:
            procesarDevolucion();
            break;
        case 6:
            imprimirReportes();
            break;
        case 7:
            buscarPublicacionPorCriterios();
            break;
        case 8:
            pasarDias();
            break;
        case 9:
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opción no válida, por favor intente de nuevo.\n";
        }
    } while (opcion != 9);
}

int main() {
    mostrarMenu();
    return 0;
}
