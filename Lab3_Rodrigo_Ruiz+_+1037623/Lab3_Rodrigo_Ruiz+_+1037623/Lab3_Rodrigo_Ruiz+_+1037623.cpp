#include "pch.h"
#pragma once
#include "Persona.h"  
#include "Estudiante.h"
#include "Profesor.h"
#include "PersonalServicio.h"
#include "Empleado.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    // Crear instancias de cada tipo de individuo
    Estudiante^ estudiante = gcnew Estudiante("Juan", "Perez", "123", "Soltero", "Ingeniería");
    Profesor^ profesor = gcnew Profesor("Maria", "Gomez", "456", "Casado", 2000, 101, "Matemáticas");
    PersonalServicio^ personalServicio = gcnew PersonalServicio("Carlos", "Lopez", "789", "Soltero", 2010, 201, "Biblioteca");

    // Realizar acciones y imprimir información
    estudiante->MatricularEnNuevoCurso("Ciencias de la Computación");
    profesor->CambiarDepartamento("Informática");
    personalServicio->TrasladarASeccion("Decanato");

    // Cambiar estado civil y reasignar despacho
    estudiante->CambiarEstadoCivil("Casado");
    profesor->ReasignarDespacho(102);

    // Imprimir información después de cambios
    estudiante->ImprimirInformacion();
    Console::WriteLine();
    profesor->ImprimirInformacion();
    Console::WriteLine();
    personalServicio->ImprimirInformacion();

    return 0;
}
