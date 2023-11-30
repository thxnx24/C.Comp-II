#include <iostream>

// Definición de la clase Node
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Definición de la clase LinkedList
class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Método para agregar un nodo al final de la lista
    void append(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            // Si la lista está vacía, el nuevo nodo será tanto la cabeza como la cola
            head = tail = newNode;
        } else {
            // Agregar el nuevo nodo al final de la lista
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Método para imprimir la lista en orden
    void printForward() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Método para imprimir la lista en orden inverso
    void printBackward() {
        Node* current = tail;
        while (current) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Crear una lista doblemente enlazada e insertar algunos elementos
    LinkedList myLinkedList;
    myLinkedList.append(1);
    myLinkedList.append(2);
    myLinkedList.append(3);

    // Imprimir la lista en orden y en orden inverso
    std::cout << "Lista en orden: ";
    myLinkedList.printForward();

    std::cout << "Lista en orden inverso: ";
    myLinkedList.printBackward();

    return 0;
}
