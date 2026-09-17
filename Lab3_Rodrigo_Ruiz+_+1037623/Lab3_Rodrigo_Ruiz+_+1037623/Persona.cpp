#include "pch.h"
#include "Persona.h"

Persona::Persona(String^ nombre, String^ apellidos, String^ id, String^ estadoCivil)
{
    Nombre = nombre;
    Apellidos = apellidos;
    Id = id;
    EstadoCivil = estadoCivil;
}
void Persona::CambiarEstadoCivil(String^ nuevoEstadoCivil)
{
    EstadoCivil = nuevoEstadoCivil;
}

void Persona::ImprimirInformacion()
{
    Console::WriteLine("Nombre: " + Nombre);
    Console::WriteLine("Apellidos: " + Apellidos);
    Console::WriteLine("ID: " + Id);
    Console::WriteLine("Estado Civil: " + EstadoCivil);
}
