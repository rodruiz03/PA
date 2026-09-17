#include "pch.h"
#include "Profesor.h"

Profesor::Profesor(String^ nombre, String^ apellidos, String^ id, String^ estadoCivil, int anoIncorporacion, int numeroDespacho, String^ departamento)
    : Empleado(nombre, apellidos, id, estadoCivil, anoIncorporacion, numeroDespacho)
{
    Departamento = departamento;
}

void Profesor::CambiarDepartamento(String^ nuevoDepartamento)
{
    Departamento = nuevoDepartamento;
}

void Profesor::ImprimirInformacion()
{
    Empleado::ImprimirInformacion();  // Llamada al método de la clase base
    Console::WriteLine("Departamento: " + Departamento);
}
