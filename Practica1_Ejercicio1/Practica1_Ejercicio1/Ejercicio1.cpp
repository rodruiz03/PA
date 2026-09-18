#include <iostream>
#include <cstdlib>
#include <ctime>

// NOMBRE: Rodrigo Ruiz
// CARNET: 1037623


/*

                  Ejercicio 1 - Reverse Array
                Inicie agregando su nombre y carnet

Escriba una función recursiva en C++ que revierta el orden de un arreglo de chars
Revertir el arreglo toma el siguiente arreglo

         [ 'a', 'b', 'c', 'd' ]

y devuelve el arreglo en orden inverso

         [ 'd', 'c', 'b', 'a' ]

Usted recibe el arreglo char * valores, asuma que el mismo esta inicializado, tiene al menos 1 dato y no es null.
Usted recibe la longitud del arreglo en la variable int longitud, asuma que el mismo es valido.
Imprima en pantalla cada pareja de cambios que realice.
     En el ejemplo anterior:
         cambiamos 'a' de la posicion 0 a la posicion 3 que tiene 'd'

*/


/*********************************************************/
/*                  SU CAMBIOS AQUI                     */
void reverseArray(char* valores, unsigned int longitud, int inicio = 0, int fin = -1) {
    if (fin == -1) {
        fin = longitud - 1;
    }

    if (inicio >= fin) {
        return;
    }

    // Intercambiar los caracteres en las posiciones inicio y fin
    std::swap(valores[inicio], valores[fin]);

    // Imprimir el intercambio
    std::cout << "Cambiados: '" << valores[inicio] << "' en la posición " << inicio << " con '" << valores[fin] << "' en la posición " << fin << std::endl;

    // Llamar recursivamente a reverseArray con los índices ajustados
    reverseArray(valores, longitud, inicio + 1, fin - 1);
}



/*********************************************************/
/*      NO EDITAR NADA A PARTIR DE ESTA LINEA            */

std::pair<char*, int> randomArray() {
    static const char caracteres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int longitud = rand() % 10 + 1;
    char* array = new char[longitud];

    for (int i = 0; i < longitud; ++i) {
        array[i] = caracteres[rand() % (sizeof(caracteres) - 1)];
    }

    return { array, longitud };
}

void printArray(char* arreglo, int longitud) {
    for (int i = 0; i < longitud; i++) {
        std::cout << arreglo[i];
    }
    std::cout << std::endl;
}

void print2(char* arreglo, int longitud) {
    for (int i = longitud; i > 0; i--) {
        std::cout << arreglo[i - 1];
    }
    std::cout << std::endl;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 1; i <= 10; ++i) {
        std::pair<char*, int>  _array = randomArray();

        char* array = _array.first;
        int longitud = _array.second;

        printArray(array, longitud);
        reverseArray(array, longitud);
        print2(array, longitud);
        delete[] array;
    }
}