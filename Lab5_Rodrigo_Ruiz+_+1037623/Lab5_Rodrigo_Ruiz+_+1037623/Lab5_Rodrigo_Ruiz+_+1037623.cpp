#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>
#include "Paciente.h"
#include "Nadador.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    // Ingreso de datos para pacientes
    std::vector<Paciente> pacientes(4);

    for (int i = 0; i < 4; ++i) {
        std::cout << "Ingrese los datos del paciente " << i + 1 << std::endl;
        pacientes[i].ingresarDatos();
    }

    // Búsqueda de pacientes por día de visita
    int diaBusqueda;
    std::cout << "Ingrese el día de visita a buscar: ";
    std::cin >> diaBusqueda;

    std::cout << "Pacientes con visita el día " << diaBusqueda << ":" << std::endl;
    for (const Paciente& paciente : pacientes) {
        if (paciente.diaVisita == diaBusqueda) {
            std::cout << "Nombre: " << paciente.nombre << std::endl;
            std::cout << "Dirección: " << paciente.direccion << std::endl;
            std::cout << "Fecha de nacimiento: " << paciente.fechaNacimiento << std::endl;
            std::cout << "Sexo: " << paciente.sexo << std::endl;
            std::cout << "Problema médico: " << paciente.problemaMedico << std::endl;
            std::cout << std::endl;
        }
    }

    // Ingreso de datos para nadadores
    std::vector<Nadador> nadadores(5);

    for (int i = 0; i < 5; ++i) {
        std::cout << "Ingrese los datos del nadador " << i + 1 << std::endl;
        std::cout << "Nombre: ";
        std::cin >> nadadores[i].nombre;
        std::cout << "Edad: ";
        std::cin >> nadadores[i].edad;
        std::cout << "Prueba: ";
        std::cin >> nadadores[i].prueba;
        std::cout << "Tiempo (minutos segundos): ";
        std::cin >> nadadores[i].minutos >> nadadores[i].segundos;
    }

    // Calcular el tiempo promedio
    double tiempoPromedio = 0;
    for (const Nadador& nadador : nadadores) {
        tiempoPromedio += nadador.minutos * 60 + nadador.segundos;
    }
    tiempoPromedio /= 5;

    // Calcular la desviación estándar
    double sumaCuadrados = 0;
    for (const Nadador& nadador : nadadores) {
        double tiempo = nadador.minutos * 60 + nadador.segundos;
        sumaCuadrados += pow(tiempo - tiempoPromedio, 2);
    }
    double desviacionEstandar = sqrt(sumaCuadrados / 5);

    std::cout << "La desviación estándar respecto al tiempo es: " << desviacionEstandar << std::endl;

    return 0;
}
