#pragma once
#include "Empleado.h"

 ref class Profesor : public Empleado
{
public:
    Profesor(String^ nombre, String^ apellidos, String^ id, String^ estadoCivil, int anoIncorporacion, int numeroDespacho, String^ departamento);

    // Atributo adicional
    String^ Departamento;

    // Método para cambiar el departamento de un profesor
    void CambiarDepartamento(String^ nuevoDepartamento);

    // Método para imprimir la información del profesor
    void ImprimirInformacion() override;
};
