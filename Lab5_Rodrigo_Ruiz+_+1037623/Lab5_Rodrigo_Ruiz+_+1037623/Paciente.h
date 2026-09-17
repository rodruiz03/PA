#pragma once
#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
class Paciente
{
public:
    std::string nombre;
    std::string direccion;
    std::string fechaNacimiento;
    char sexo;
    int diaVisita;
    std::string problemaMedico;

    void ingresarDatos();
};
#endif // PACIENTE_H
