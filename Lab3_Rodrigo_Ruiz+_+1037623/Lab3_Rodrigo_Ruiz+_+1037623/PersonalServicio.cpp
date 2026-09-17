#include "pch.h"
#include "PersonalServicio.h"

PersonalServicio::PersonalServicio(String^ nombre, String^ apellidos, String^ id, String^ estadoCivil, int anoIncorporacion, int numeroDespacho, String^ seccion)
    : Empleado(nombre, apellidos, id, estadoCivil, anoIncorporacion, numeroDespacho)
{
    Seccion = seccion;
}

void PersonalServicio::TrasladarASeccion(String^ nuevaSeccion)
{
    Seccion = nuevaSeccion;
}

void PersonalServicio::ImprimirInformacion()
{
    Empleado::ImprimirInformacion();  // Llamada al método de la clase base
    Console::WriteLine("Sección: " + Seccion);
}
