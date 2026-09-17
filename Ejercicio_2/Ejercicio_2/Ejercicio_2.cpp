#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Arreglo.h"

// NOMBRE: Rodrigo Ruiz
// CARNET:1037623

/*

            Ejercicio 2 - Clase para manejo de arreglos
                Inicie agregando su nombre y carnet

Cree una clase que permita almacenar un arreglo unidimensional de chars.
La clase debe tener métodos para insertar, eliminar y buscar elementos en el arreglo,
así como para imprimir el arreglo.

Utiliza punteros para manejar la memoria dinámica.

Use la plantilla de la clase para desarrollar su solucion.

*/

class ManejadorArreglo {
private:
    char* _arreglo;
    int _longitud; // almacena la longitud mas reciente del arreglo. Se modifica por agregarElemento(), eliminarElementoAlFinal()
public:
    ManejadorArreglo(char* arreglo, int longitud) {
        _arreglo = arreglo;
        _longitud = longitud;
    }

    char cambiarValorEnIndice(int indice, char valor) {
        // Reemplaza el valor del indice en el arreglo. Retorna el dato almacenado previo al cambio.
        return 0;
    }

    int agregarElementoAlFinal(char valor) {
        // Inserta un elemento al final del arreglo, extendiendo la capacidad del mismo. Retorna la nueva longitud.
        return _longitud;
    }
    void eliminarElementoAlFinal() {
        // Elimina el ultimo elemento del arreglo, reduciendo la capacidad del mismo. Retorna la nueva longitud
    }
    void imprimir() {
        // imprime todos los valores del arreglo
    }
    void imprimir(int inicio, int fin) {
        // imprime los valores del arreglo en el rango dado.
    }

    int buscarValor(char valor) {
        // Busca el valor en el arreglo, retornando el indice de la primera coincidencia. Caso contrario, retorna -1.
        return -1;
    }
};

int main() {
    Arreglo manejador(10);

    manejador.cambiarValorEnIndice(0, 'a');
    manejador.cambiarValorEnIndice(1, 'b');
    manejador.cambiarValorEnIndice(2, 'c');
    manejador.imprimir(); // Debería imprimir: a b c ? ? ? ? ? ? ?

    manejador.agregarElementoAlFinal('z');
    manejador.imprimir(); // Debería imprimir: a b c ? ? ? ? ? ? ? z
    manejador.eliminarElementoAlFinal();
    manejador.imprimir(); // Debería imprimir: a b c ? ? ? ? ? ? ?

    std::cout << "Indice de 'b' en el arreglo: " << manejador.buscarValor('b') << std::endl; // Debería imprimir: 1

    manejador.imprimir(0, 2); // Debería imprimir: a b c
    return 0;
}
