#pragma once
#include "Empleado.h"

ref class PersonalServicio : public Empleado
{
private:
    // Atributo adicional
    String^ Seccion;
public:
    PersonalServicio(String^ nombre, String^ apellidos, String^ id, String^ estadoCivil, int anoIncorporacion, int numeroDespacho, String^ seccion);

    

    // Método para trasladar a un empleado del personal de servicio a otra sección
    void TrasladarASeccion(String^ nuevaSeccion);

    // Método para imprimir la información del personal de servicio
    void ImprimirInformacion() override;
};