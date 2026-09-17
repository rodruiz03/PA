#include "pch.h"
#include "Paciente.h"
#include <iostream>

void Paciente::ingresarDatos() {
    std::cout << "Nombre: ";
    std::cin >> nombre;
    std::cout << "Direccion: ";
    std::cin >> direccion;
    std::cout << "Fecha de nacimiento (dd/mm/aaaa): ";
    std::cin >> fechaNacimiento;
    std::cout << "Sexo (M/F): ";
    std::cin >> sexo;
    std::cout << "Dia de visita: ";
    std::cin >> diaVisita;
    std::cout << "Problema medico: ";
    std::cin >> problemaMedico;
}
