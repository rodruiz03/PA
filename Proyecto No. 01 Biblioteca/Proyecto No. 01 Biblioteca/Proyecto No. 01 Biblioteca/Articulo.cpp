#include "Articulo.h"
#include "iostream"

float Articulo::calcularMulta(int diasRetraso) {
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

void Articulo::crearArticulo() {
    std::cout << " ** Nueva Articulo **\n" << std::endl;
    std::cout << "Ingrese la id del articulo: " << std::endl;
    std::cin >> id;
    std::cout << "Ingrese el titulo del articulo: " << std::endl;
    std::cin >> titulo;
    std::cout << "Ingrese el arbitro del articulo: " << std::endl;
    std::cin >> arbitro;
    std::cout << "Ingrese la materia del articulo: " << std::endl;
    std::cin >> materia;
    std::cout << "Ingrese la cantidad de ejemplares del articulo: " << std::endl;
    std::cin >> ejemplares;
    while (ejemplares < 0) {
        std::cout << "No puede haber un numero negativo de ejemplares por articulo, intentelo de nuevo: " << std::endl;
        std::cin >> ejemplares;
    }
    char disponibilidad;
    std::cout << "Ingrese si esta disponible el articulo (S,N): " << std::endl;
    std::cin >> disponibilidad;
    disponibilidad = toupper(disponibilidad);
    if (disponibilidad == 'N') {
        disponible == false;
    }
    else {
        disponible == true;
    }
}