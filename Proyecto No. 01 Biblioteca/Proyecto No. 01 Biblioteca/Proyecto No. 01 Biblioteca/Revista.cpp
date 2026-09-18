#include "Revista.h"
#include "iostream"
#include "Publicacion.h"
#include <string>

float Revista::calcularMulta(int diasRetraso) {
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

void Revista::crearRevista() {
    std::cout << " ** Nueva Revista **\n" << std::endl;
    std::cout << "Ingrese la id de la revista: " << std::endl;
    std::cin >> id;
    std::cout << "Ingrese el titulo de la revista: " << std::endl;
    std::cin >> titulo;
    std::cout << "Ingrese el año de la revista: " << std::endl;
    std::cin >> año;
    std::cout << "Ingrese el numero de la revista: " << std::endl;
    std::cin >> numero;
    std::cout << "Ingrese la materia de la revista: " << std::endl;
    std::cin >> materia;
    std::cout << "Ingrese la cantidad de ejemplares de la revista: " << std::endl;
    std::cin >> ejemplares;
    while (ejemplares < 0) {
        std::cout << "No puede haber un numero negativo de ejemplares por revista, intentelo de nuevo: " << std::endl;
        std::cin >> ejemplares;
    }
    char disponibilidad;
    std::cout << "Ingrese si esta disponible la revista (S,N): " << std::endl;
    std::cin >> disponibilidad;
    disponibilidad = toupper(disponibilidad);
    if (disponibilidad == 'N') {
        disponible == false;
    }
    else {
        disponible == true;
    }
}
