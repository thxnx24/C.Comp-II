#include <iostream>

template <class T>
struct nodo {
    T data;
    nodo* next;

    // Constructor
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

template <class T, class Predicate>
void split(nodo<T>*& h1, nodo<T>*& h2, Predicate cumple)
{
    // Traverse the original list
    nodo<T>* current = h1;
    nodo<T>* prev = nullptr;

    while (current != nullptr) {
        // Check the predicate
        if (cumple(current->data)) {
            // Move to the next node in the original list
            prev = current;
            current = current->next;
        } else {
            // Move the node to the second list (H2)
            if (prev == nullptr) {
                h1 = current->next;
            } else {
                prev->next = current->next;
            }

            // Insert the node at the beginning of the second list (H2)
            current->next = h2;
            h2 = current;

            // Move to the next node in the original list
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

    nodo<int>* h2 = nullptr;  // Empty list for numbers not satisfying the predicate

    std::cout << "Choose predicate:\n1. Par\n2. Impar\n";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        par<int> predicate;  // Functor for checking if a number is even
        split(h1, h2, predicate);
    } else if (choice == 2) {
        impar<int> predicate;  // Functor for checking if a number is odd
        split(h1, h2, predicate);
    } else {
        std::cout << "Invalid choice.\n";
        return 1;
    }

    // Print the contents of H1
    nodo<int>* current = h1;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;

    // Print the contents of H2
    current = h2;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    return 0;
}
