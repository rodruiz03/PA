#include "pch.h"
#include <iostream>
#include <stdexcept>  // Necesario para std::runtime_error

class Nodo {
public:
    char dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo() : dato('\0'), siguiente(nullptr), anterior(nullptr) {}
};

class Lista {
private:
    int longitud;
    Nodo* Head;
    Nodo* Tail;

public:
    Lista() : longitud(0), Head(nullptr), Tail(nullptr) {}

    void Add(char X) {
        Nodo* nuevoNodo = new Nodo();
        nuevoNodo->dato = X;

        if (Head == nullptr) {
            nuevoNodo->siguiente = nuevoNodo;
            nuevoNodo->anterior = nuevoNodo;
            Head = nuevoNodo;
            Tail = nuevoNodo;
        }
        else {
            nuevoNodo->anterior = Tail;
            nuevoNodo->siguiente = Head;
            Tail->siguiente = nuevoNodo;
            Head->anterior = nuevoNodo;
            Tail = nuevoNodo;
        }
        longitud++;
    }

    void Enqueue(char X) {
        Add(X);
    }

    char Dequeue() {
        if (Head == nullptr) {
            throw std::runtime_error("Queue is empty");
        }
        char dato = Head->dato;
        Remove(dato);
        return dato;
    }

    char QueuePeek() {
        if (Head == nullptr) {
            throw std::runtime_error("Queue is empty");
        }
        return Head->dato;
    }

    void Push(char X) {
        Add(X);
    }

    char Pop() {
        if (Tail == nullptr) {
            throw std::runtime_error("Stack is empty");
        }
        char dato = Tail->dato;
        Remove(dato);
        return dato;
    }

    char StackPeek() {
        if (Tail == nullptr) {
            throw std::runtime_error("Stack is empty");
        }
        return Tail->dato;
    }

    bool Replace(char charAReemplazar, char Remplazo) {
        Nodo* actual = Head;
        bool encontrado = false;

        if (Head != nullptr) {
            do {
                if (actual->dato == charAReemplazar) {
                    actual->dato = Remplazo;
                    encontrado = true;
                }
                actual = actual->siguiente;
            } while (actual != Head);
        }

        return encontrado;
    }

    bool Remove(char X) {
        if (Head == nullptr) return false;  // Lista vacía
        Nodo* actual = Head;
        bool encontrado = false;

        do {
            if (actual->dato == X) {
                encontrado = true;
                if (actual == Head && actual == Tail) {
                    delete actual;
                    Head = nullptr;
                    Tail = nullptr;
                }
                else {
                    actual->anterior->siguiente = actual->siguiente;
                    actual->siguiente->anterior = actual->anterior;
                    if (actual == Head) {
                        Head = actual->siguiente;
                    }
                    if (actual == Tail) {
                        Tail = actual->anterior;
                    }
                    delete actual;
                }
                longitud--;
                break;
            }
            actual = actual->siguiente;
        } while (actual != Head);

        return encontrado;
    }

    int getLongitud() {
        return longitud;
    }

    void ImprimirLista() {
        if (Head == nullptr) return;
        Nodo* actual = Head;

        do {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        } while (actual != Head);
        std::cout << std::endl;
    }
};

int main() {
    Lista* lista1 = new Lista();

    for (int i = 0; i < 10; ++i) {
        lista1->Enqueue(static_cast<char>(i + 65));  // Usando ASCII para letras mayúsculas
    }

    std::cout << "Lista original: ";
    lista1->ImprimirLista();
    std::cout << "\n";

    std::cout << "Peek (Cola): " << lista1->QueuePeek() << "\n";
    std::cout << "Dequeue: " << lista1->Dequeue() << "\n";
    std::cout << "Lista después de Dequeue: ";
    lista1->ImprimirLista();
    std::cout << "\n";

    if (lista1->Replace('B', 'Z')) {
        std::cout << "Caracter reemplazado.\n";
    }
    else {
        std::cout << "Caracter no encontrado.\n";
    }

    std::cout << "Lista modificada: ";
    lista1->ImprimirLista();
    std::cout << "\n";

    // Pruebas de pila
    std::cout << "Peek (Pila): " << lista1->StackPeek() << "\n";
    std::cout << "Pop (Pila): " << lista1->Pop() << "\n";
    std::cout << "Lista después de Pop (Pila): ";
    lista1->ImprimirLista();
    std::cout << "\n";

    delete lista1;  // No olvides liberar la memoria

    return 0;
}
