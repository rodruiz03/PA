#include <iostream>

class Nodo {
public:
    char dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo() {
        dato = '\0';
        siguiente = nullptr;
        anterior = nullptr;
    }
};

class Lista {
private:
    int longitud;
    Nodo* Head;
    Nodo* Tail;

public:
    Lista() {
        longitud = 0;
        Head = nullptr;
        Tail = nullptr;
    }

    void Add(char X) {
        longitud++;
        Nodo* nuevoNodo = new Nodo();
        nuevoNodo->dato = X;

        if (Head == nullptr) {
            //Caso 1 - No hay elementos en la lista
            nuevoNodo->siguiente = nullptr;
            nuevoNodo->anterior = nullptr;
            Head = nuevoNodo;
            Tail = nuevoNodo;
        }
        else {
            //Caso 2 - Hay elementos en la lista
            nuevoNodo->anterior = Tail;
            Tail->siguiente = nuevoNodo;
            Tail = nuevoNodo;
        }
    }

    bool Replace(char charAReemplazar, char Remplazo) {
        Nodo* actual = Head;
        bool encontrado = false;

        while (actual != nullptr) {
            if (actual->dato == charAReemplazar) {
                actual->dato = Remplazo;
                encontrado = true;
            }
            actual = actual->siguiente;
        }

        return encontrado;
    }

    bool Remove(char X) {
        Nodo* actual = Head;

        while (actual != nullptr) {
            Nodo* temp = actual->siguiente;
            if (actual->dato == X) {
                //Caso 1 - inicial
                Nodo* siguiente = Head->siguiente;
                if (actual == Head) {
                    siguiente->anterior;
                }
                delete Head;
                Head = siguiente;
            }
            else if (actual == Tail) {
                //Caso 2 - final
                Tail->anterior->siguiente = nullptr;
                delete Tail;
            }
            else {
                //Caso 3 - nodo interior
                Nodo* anterior = actual->anterior;
                Nodo* siguiente = actual->siguiente;

                if (anterior != nullptr) {
                    anterior->siguiente = siguiente;
                }
                if (siguiente != nullptr) {
                    siguiente->anterior = anterior;
                }
                delete actual;
            }
            actual = temp;
        }
    }

    int getLongitud() {
        return longitud;
    }

    void ImprimirLista() {
        Nodo* actual = Head;

        while (actual != nullptr) {
            std::cout << actual->dato;
            actual = actual->siguiente;
        }
    }
};

int main() {
    Lista* lista1 = new Lista();

    for (int i = 0; i < 10; ++i) {
        lista1->Add((char)(i + 65)); // Usando ASCII para letras mayúsculas
    }

    std::cout << "Lista original: ";
    lista1->ImprimirLista();
    std::cout << "\n";

    if (lista1->Replace('A', 'Z')) {
        std::cout << "Caracter reemplazado.\n";
    }
    else {
        std::cout << "Caracter no encontrado.\n";
    }

    std::cout << "Lista modificada: ";
    lista1->ImprimirLista();
    std::cout << "\n";

    return 0;
}
