#pragma once
using namespace System;
#include "Persona.h"
ref class Estudiante : public Persona
{
private:
    String^ Curso;
public:
    Estudiante(String^ nombre, String^ apellidos, String^ id, String^ estadoCivil, String^ curso);

    // Atributo adicional
    

    // Método para matricular a un estudiante en un nuevo curso
    void MatricularEnNuevoCurso(String^ nuevoCurso);

    // Método para imprimir la información del estudiante
    void ImprimirInformacion() override;
};

