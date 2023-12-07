#include <iostream>
using namespace std;

template <class T>
struct nodo {
    T data;
    nodo* next;
    nodo(const T& value) : data(value), next(nullptr) {}
};

bool esPar(int value) {
    return value % 2 == 0;
}

bool esImpar(int value) {
    return value % 2 != 0;
}

template <class T>
void split(nodo<T>*& a, nodo<T>*& b, bool (*decide)(T))
{
    // Recorre lista
    nodo<T>* a_current = a;       
    nodo<T>* a_prev = nullptr;

    while (a_current != nullptr) {
       
        if (decide(a_current->data)) {  
            a_prev = a_current;
            a_current = a_current->next;
        } else {
            // Mueve el nodo a la segunda lista (b)
            if (a_prev == nullptr) {
                a = a_current->next;
            } else {
                a_prev->next = a_current->next;
            }

            // Inserta el nodo al principio de la segunda lista (b)
            a_current->next = b;
            b = a_current;

            // Mover al siguiente nodo de la lista original
            a_current = (a_prev == nullptr) ? a : a_prev->next;
        }
    }
}

int main(){
    
    nodo<int>* a = new nodo<int>(1);
    a->next = new nodo<int>(2);
    a->next->next = new nodo<int>(3);
    a->next->next->next = new nodo<int>(4);
    a->next->next->next->next = new nodo<int>(5);
    a->next->next->next->next->next = new nodo<int>(6);
    a->next->next->next->next->next->next = new nodo<int>(7);
    a->next->next->next->next->next->next->next = new nodo<int>(8);
    a->next->next->next->next->next->next->next->next = new nodo<int>(9);
    a->next->next->next->next->next->next->next->next->next = new nodo<int>(81);
    a->next->next->next->next->next->next->next->next->next->next = new nodo<int>(82);
    a->next->next->next->next->next->next->next->next->next->next->next = new nodo<int>(58);
    a->next->next->next->next->next->next->next->next->next->next->next->next = new nodo<int>(75);
    a->next->next->next->next->next->next->next->next->next->next->next->next->next = new nodo<int>(34);

    nodo<int>* b = nullptr;

    cout << "Elige: \n1. Par\n2. Impar\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        split(a, b, esPar);
    } else if (choice == 2) {
        split(a, b, esImpar);
    } else {
        cout << "Elección inválida.\n";
        return 1;
    }
    
    nodo<int>* current = a;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;

    current = b;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    // Liberar memoria
    while (a != nullptr) {
        nodo<int>* temp = a;
        a = a->next;
        delete temp;
    }

    while (b != nullptr) {
        nodo<int>* temp = b;
        b = b->next;
        delete temp;
    }

    return 0;
}
