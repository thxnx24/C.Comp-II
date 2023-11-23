/*
Si cumple --> Se queda en H1
Si no cumple, se mueve H2 (no borrar y crear)
*/
#include <iostream>
using namespace std;

template <class T>
struct nodo {
    T data;
    nodo* next;
    nodo(const T& value) : data(value), next(nullptr) {}
};

template <class T>
struct par {
    bool operator()(const T& value) const {
        return value % 2 == 0;
    }
};

template <class T>
struct impar {
    bool operator()(const T& value) const {
        return value % 2 != 0;
    }
};

template <class T, class elige>
void split(nodo<T>*& h1, nodo<T>*& h2, elige cumple)
{
    //Recorre lista
    nodo<T>* current = h1;       
    nodo<T>* prev = nullptr;

    while (current != nullptr) {
       
        if (cumple(current->data)){  
            prev = current;
            current = current->next;
        } else {
            // Mueve el nodo a la segunda lista (H2)
            if (prev == nullptr) {
                h1 = current->next;
            } else {
                prev->next = current->next;
            }

            //Inserta el nodo al principio de la segunda lista (H2)
            current->next = h2;
            h2 = current;

            //Mover al siguiente nodo de la lista original
            current = (prev == nullptr) ? h1 : prev->next;
        }
    }
}

int main() {
    
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

    nodo<int>* h2 = nullptr;  // Empty list for numbers not satisfying the elige

    cout << "Elige: \n1. Par\n2. Impar\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        par<int> elige;  // Functor for checking if a number is even
        split(h1, h2, elige);
    } else if (choice == 2) {
        impar<int> elige;  // Functor for checking if a number is odd
        split(h1, h2, elige);
    } else {
        cout << "Elección inválida.\n";
        return 1;
    }

    // Print the contents of H1
    nodo<int>* current = h1;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;

    // Print the contents of H2
    current = h2;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
}
