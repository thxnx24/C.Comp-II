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
void split(nodo<T>*& h1, nodo<T>*& h2, bool (*decide)(T))
{
    // Recorre lista
    nodo<T>* current = h1;       
    nodo<T>* prev = nullptr;

    while (current != nullptr) {
       
        if (decide(current->data)) {  
            prev = current;
            current = current->next;
        } else {
            // Mueve el nodo a la segunda lista (H2)
            if (prev == nullptr) {
                h1 = current->next;
            } else {
                prev->next = current->next;
            }

            // Inserta el nodo al principio de la segunda lista (H2)
            current->next = h2;
            h2 = current;

            // Mover al siguiente nodo de la lista original
            current = (prev == nullptr) ? h1 : prev->next;
        }
    }
}

int main(){
    
    nodo<int>* h1 = new nodo<int>(1);
    h1->next = new nodo<int>(2);
    h1->next->next = new nodo<int>(3);
    h1->next->next->next = new nodo<int>(4);
    h1->next->next->next->next = new nodo<int>(5);
    h1->next->next->next->next->next = new nodo<int>(6);
    h1->next->next->next->next->next->next = new nodo<int>(7);
    h1->next->next->next->next->next->next->next = new nodo<int>(8);
    h1->next->next->next->next->next->next->next->next = new nodo<int>(9);
    h1->next->next->next->next->next->next->next->next->next = new nodo<int>(81);
    h1->next->next->next->next->next->next->next->next->next->next = new nodo<int>(82);
    h1->next->next->next->next->next->next->next->next->next->next->next = new nodo<int>(58);
    h1->next->next->next->next->next->next->next->next->next->next->next->next = new nodo<int>(75);
    h1->next->next->next->next->next->next->next->next->next->next->next->next->next = new nodo<int>(34);

    nodo<int>* h2 = nullptr;

    cout << "Elige: \n1. Par\n2. Impar\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        split(h1, h2, esPar);
    } else if (choice == 2) {
        split(h1, h2, esImpar);
    } else {
        cout << "Elección inválida.\n";
        return 1;
    }
    
    nodo<int>* current = h1;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;

    current = h2;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    // Liberar memoria
    while (h1 != nullptr) {
        nodo<int>* temp = h1;
        h1 = h1->next;
        delete temp;
    }

    while (h2 != nullptr) {
        nodo<int>* temp = h2;
        h2 = h2->next;
        delete temp;
    }

    return 0;
}
