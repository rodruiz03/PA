#include <iostream>
#include "Usuario.h"
#include "Cliente.h"
#include "Publicacion.h"
#include "Libro.h"
#include "Revista.h"
#include "Articulo.h"
#include "especialista.h"
#include <stdlib.h>

void menuCliente();
void menuEspecialista();

int main()
{
    bool salir = false;

    do {
        Usuario usuario;
        Publicacion publicacion;
        Libro libro;
        Revista revista;
        Articulo articulo;
        menuEspecialista();
        int opcion;
        std::cin >> opcion;
        switch (opcion) {
        case 1:
            if (usuario.crearUsuario(1) == 1) {
                menuCliente();
            }
            else {
                menuEspecialista();
            }
            break;
        case 2:
            switch (publicacion.ingresarPublicacion(' ')) {
            case 'L':
                libro.crearLibro();
                break;
            case 'R':
                revista.crearRevista();
                break;
            case 'A':
                articulo.crearArticulo();
                break;
            }
            break;
        case 3:
            // *
            break;
        case 4:
            // *
            break;
        case 5:
            // *
            break;
        case 6: // Opción para salir
            salir = true;
            exit;
        default:
            if (opcion < 1 || opcion > 6) {
                std::cout << "Opción inválida. Por favor, seleccione una opción válida." << std::endl;
            }
            break;
        }
    } while (!salir);

    return 0;
}
void menuCliente() {
    std::cout << "\n * CLIENTE *" << std::endl;
    std::cout << "1. Crear nuevo usuario" << std::endl;
    std::cout << "2. Buscar un libro" << std::endl;
    std::cout << "3. Mostrar registros" << std::endl;
    std::cout << "\nElija la opcion que desea realizar: ";
}
void menuEspecialista() {
    std::cout << "\n * ESPECILISTA *" << std::endl;
    std::cout << "1. Crear nuevo usuario" << std::endl;
    std::cout << "2. Ingresar una publicación" << std::endl;
    std::cout << "3. Buscar una publicación" << std::endl;
    std::cout << "4. Realizar registro" << std::endl;
    std::cout << "5. Mostrar registros" << std::endl;
    std::cout << "6. Salir del programa" << std::endl;
    std::cout << "\nEliga la opcion que desea realizar: ";
}