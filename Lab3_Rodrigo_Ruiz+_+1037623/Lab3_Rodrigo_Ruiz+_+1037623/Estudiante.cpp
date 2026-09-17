#include "pch.h"
#include "Estudiante.h"

Estudiante::Estudiante(String^ nombre, String^ apellidos, String^ id, String^ estadoCivil, String^ curso)
    : Persona(nombre, apellidos, id, estadoCivil)
{
    Curso = curso;

}

void Estudiante::MatricularEnNuevoCurso(String^ nuevoCurso)
{
    Curso = nuevoCurso;
}

void Estudiante::ImprimirInformacion()
{
    Persona::ImprimirInformacion();  // Llamada al método de la clase base
    Console::WriteLine("Curso: " + Curso);
}
