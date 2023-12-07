#include <iostream>
using namespace std;

class nodo {
public: 
    nodo() {
        next = nullptr;
    }
    nodo(int i, nodo* in = nullptr) : info(i), next(in) {}

    int info;
    nodo* next;
};

void split(nodo*& a, nodo*& b, bool (*decide)(int)) {
    // Recorre lista
    nodo* a_current = a;
    nodo* a_prev = nullptr;

    while (a_current != nullptr) {
        if (decide(a_current->info)) {
            a_prev = a_current;
            a_current = a_current->next;
        } else {
            // Mueve el nodo a la segunda lista (b)
            if (a_prev == nullptr) {
                a = a_current->next;
            } else {
                a_prev->next = a_current->next;
            }

            // Inserta el nodo al final de la segunda lista (b)
            if (b == nullptr) {
                b = a_current;
                b->next = nullptr;
            } else {
                nodo* b_current = b;
                while (b_current->next != nullptr) {
                    b_current = b_current->next;
                }
                b_current->next = a_current;
                a_current->next = nullptr;
            }

            // Mover al siguiente nodo de la lista original
            a_current = (a_prev == nullptr) ? a : a_prev->next;
        }
    }
}

// Función decide para probar con valores pares
bool decidePar(int value) {
    return value % 2 == 0;
}

int main() {
    nodo* a = new nodo(1);
    a->next = new nodo(2);
    a->next->next = new nodo(3);
    a->next->next->next = new nodo(4);
    a->next->next->next->next = new nodo(5);
    a->next->next->next->next->next = new nodo(6);
    a->next->next->next->next->next->next = new nodo(34);
    a->next->next->next->next->next->next->next = new nodo(12);
    a->next->next->next->next->next->next->next->next = new nodo(8);



    nodo* b = nullptr;

    cout << "Antes de la separación:\n";
    cout << "Lista a: ";
    nodo* current = a;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;

    cout << "Lista b: ";
    current = b;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;

    split(a, b, decidePar);

    cout << "Después de la separación:\n";
    cout << "Lista a: ";
    current = a;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;

    cout << "Lista b: ";
    current = b;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;

    // Liberar memoria
    while (a != nullptr) {
        nodo* temp = a;
        a = a->next;
        delete temp;
    }

    while (b != nullptr) {
        nodo* temp = b;
        b = b->next;
        delete temp;
    }

    return 0;
}
