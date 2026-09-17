#pragma once
#include "Ciclista.h"
#include <vector>
#include <algorithm>
#include <random>

public ref class Competencia
{
private:
    System::Collections::Generic::List<Ciclista^>^ ciclistas;
    System::Collections::Generic::List<Ciclista^>^ ciclistasEliminados;
    int pruebaActual;
    int numeroCarrera;

public:
    Competencia()
    {
        ciclistas = gcnew System::Collections::Generic::List<Ciclista^>();
        ciclistasEliminados = gcnew System::Collections::Generic::List<Ciclista^>();
        pruebaActual = 0; // 0 para velocidad, 1 para persecución
        numeroCarrera = 1;
    }

    void AgregarCiclista(Ciclista^ ciclista)
    {
        ciclistas->Add(ciclista);
    }

    void EjecutarPrueba()
    {
        if (ciclistas->Count < 3)
        {
            Console::WriteLine("No hay suficientes ciclistas para continuar la competencia.");
            return;
        }

        Console::WriteLine("Carrera #" + numeroCarrera);

        if (pruebaActual == 0)
        {
            EjecutarPruebaVelocidad();
        }
        else
        {
            EjecutarPruebaPersecucion();
        }

        pruebaActual = 1 - pruebaActual; // Alternar entre velocidad y persecución
        numeroCarrera++;
    }

    void EjecutarPruebaVelocidad()
    {
        if (ciclistas->Count < 4)
        {
            Console::WriteLine("No hay suficientes ciclistas para la prueba de velocidad.");
            return;
        }

        std::vector<int> indices;
        for (int i = 0; i < ciclistas->Count; ++i)
        {
            indices.push_back(i);
        }
        std::shuffle(indices.begin(), indices.end(), std::mt19937{ std::random_device{}() });

        auto participantes = gcnew System::Collections::Generic::List<Ciclista^>();
        for (int i = 0; i < 4; ++i)
        {
            participantes->Add(ciclistas[indices[i]]);
            ciclistas[indices[i]]->IncrementarPruebasParticipadas();
        }

        participantes[0]->AnadirPuntos(4);
        participantes[1]->AnadirPuntos(1);
        ciclistasEliminados->Add(participantes[3]);
        ciclistas->Remove(participantes[3]);

        MostrarResultados(participantes);
    }

    void EjecutarPruebaPersecucion()
    {
        if (ciclistas->Count < 3)
        {
            Console::WriteLine("No hay suficientes ciclistas para la prueba de persecución.");
            return;
        }

        std::vector<int> indices;
        for (int i = 0; i < ciclistas->Count; ++i)
        {
            indices.push_back(i);
        }
        std::shuffle(indices.begin(), indices.end(), std::mt19937{ std::random_device{}() });

        auto participantes = gcnew System::Collections::Generic::List<Ciclista^>();
        for (int i = 0; i < 3; ++i)
        {
            participantes->Add(ciclistas[indices[i]]);
            ciclistas[indices[i]]->IncrementarPruebasParticipadas();
        }

        participantes[0]->AnadirPuntos(3);
        ciclistasEliminados->Add(participantes[2]);
        ciclistas->Remove(participantes[2]);

        MostrarResultados(participantes);
    }

    void MostrarResultados(System::Collections::Generic::List<Ciclista^>^ participantes)
    {
        Console::WriteLine("Participantes:");
        for each (Ciclista ^ participante in participantes)
        {
            Console::WriteLine(participante->nombre + " - " + participante->puntos + " puntos");
        }

        Console::WriteLine("Eliminados:");
        for each (Ciclista ^ ciclista in ciclistasEliminados)
        {
            Console::WriteLine(ciclista->nombre + " - " + ciclista->puntos + " puntos");
        }

        Console::WriteLine("Número de eliminados: " + ciclistasEliminados->Count);
        Console::WriteLine();
    }

    void MostrarGanador()
    {
        Ciclista^ ganador = nullptr;
        for each (Ciclista ^ ciclista in ciclistas)
        {
            if (ganador == nullptr || ciclista->puntos > ganador->puntos)
            {
                ganador = ciclista;
            }
        }

        if (ganador != nullptr)
        {
            Console::WriteLine("Ganador: " + ganador->nombre + " con " + ganador->puntos + " puntos.");
        }
        else
        {
            Console::WriteLine("No hay ganador.");
        }
    }

    property System::Collections::Generic::List<Ciclista^>^ ListaCiclistas
    {
        System::Collections::Generic::List<Ciclista^>^ get() { return ciclistas; }
    }
};
