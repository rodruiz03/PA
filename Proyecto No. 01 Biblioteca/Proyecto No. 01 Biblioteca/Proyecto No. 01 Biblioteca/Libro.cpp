#include "iostream"
#include "libro.h"
#include "Publicacion.h"

float Libro::calcularMulta(int diasRetraso) {
    float cuotaDefecto = 10.50; // Cuota por defecto
    float porcentaje = 0.0;

    if (ejemplares < 10) {
        porcentaje = 0.30;
    }
    else if (ejemplares >= 10 && ejemplares <= 20) {
        porcentaje = 0.20;
    }
    else {
        porcentaje = 0.05;
    }

    return cuotaDefecto + (cuotaDefecto * porcentaje * diasRetraso);
}

void Libro::crearLibro() {
    std::cout << " ** Nuevo Libro **\n" << std::endl;
    std::cout << "Ingrese la id del libro: " << std::endl;
    std::cin >> id;
    std::cout << "Ingrese el titulo del libro: " << std::endl;
    std::cin >> titulo;
    std::cout << "Ingrese el autor del libro: " << std::endl;
    std::cin >> autor;
    std::cout << "Ingrese la editorial del libro: " << std::endl;
    std::cin >> editorial;
    std::cout << "Ingrese la materia del libro: " << std::endl;
    std::cin >> materia;
    std::cout << "Ingrese la cantidad de ejemplares del libro: " << std::endl;
    std::cin >> ejemplares;
    while (ejemplares < 0) {
        std::cout << "No puede haber un numero negativo de ejemplares por libro, intentelo de nuevo: " << std::endl;
        std::cin >> ejemplares;
    }
    char disponibilidad;
    std::cout << "Ingrese si esta disponible el libro (S,N): " << std::endl;
    std::cin >> disponibilidad;
    disponibilidad = toupper(disponibilidad);
    if (disponibilidad == 'N') {
        disponible == false;
    }
    else {
        disponible == true;
    }
}