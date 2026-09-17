#include "pch.h"
#include "Competencia.h"

int main()
{
    Competencia^ competencia = gcnew Competencia();

    competencia->AgregarCiclista(gcnew Ciclista("Ciclista 1", "Club A", "Velocidad"));
    competencia->AgregarCiclista(gcnew Ciclista("Ciclista 2", "Club B", "Velocidad"));
    competencia->AgregarCiclista(gcnew Ciclista("Ciclista 3", "Club C", "Persecución"));
    competencia->AgregarCiclista(gcnew Ciclista("Ciclista 4", "Club D", "Persecución"));
    competencia->AgregarCiclista(gcnew Ciclista("Ciclista 5", "Club E", "Velocidad"));

    while (competencia->ListaCiclistas->Count >= 3)
    {
        competencia->EjecutarPrueba();
    }

    competencia->MostrarGanador();

    return 0;
}
