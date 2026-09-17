#pragma once
using namespace System;
#include "Persona.h"
ref class Empleado : public Persona
{
private:
    int AnoIncorporacion;
    int NumeroDespacho;
public:
    Empleado(String^ nombre, String^ apellidos, String^ id, String^ estadoCivil, int anoIncorporacion, int numeroDespacho);


    // Método para reasignar despacho a un empleado
    void ReasignarDespacho(int nuevoNumeroDespacho);

    // Método para imprimir la información del empleado
    
    void ImprimirInformacion() override;
};
