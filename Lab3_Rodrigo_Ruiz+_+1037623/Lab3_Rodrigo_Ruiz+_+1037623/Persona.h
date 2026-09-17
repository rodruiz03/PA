#pragma once
using namespace System;
 ref class Persona
{
private:
    // Atributos
    String^ Nombre;
    String^ Apellidos;
    String^ Id;
    String^ EstadoCivil;
public:
    Persona(String^ nombre, String^ apellidos, String^ id, String^ estadoCivil);

   

    // Método para cambiar el estado civil de una persona
    void CambiarEstadoCivil(String^ nuevoEstadoCivil);

    // Método para imprimir la información de la persona
    virtual void ImprimirInformacion();
};

