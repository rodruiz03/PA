#include "pch.h"
#include "Empleado.h"
#include <iostream>

using namespace System;

Empleado::Empleado(String^ nombre, String^ apellidos, String^ id, String^ estadoCivil, int anoIncorporacion, int numeroDespacho)
    : Persona(nombre, apellidos, id, estadoCivil)
{
    AnoIncorporacion = anoIncorporacion;
    NumeroDespacho = numeroDespacho;
}

void Empleado::ReasignarDespacho(int nuevoNumeroDespacho)
{
    NumeroDespacho = nuevoNumeroDespacho;
}

void Empleado::ImprimirInformacion()
{
    Persona::ImprimirInformacion();  // Llamada al método de la clase base
    Console::WriteLine("Año de Incorporación: " + AnoIncorporacion);
    Console::WriteLine("Número de Despacho: " + NumeroDespacho);
}