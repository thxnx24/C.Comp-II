/*
Hacer una cola/fila, que tenga
-push
-pop
-empty
-~ (destructor)
                      head y tail --> null
-print
*/

#include <iostream>
#include <string>
using namespace std;

template <class T>
struct Node {
    T value;
    Node<T>* next;
    Node(T v, Node<T>* n = NULL) {
        value = v;
        next = n;
    }
};

template <class T>
struct cola {
    Node<T>* head = NULL;
    Node<T>* tail = NULL;
    void push(T value);
    bool pop(T& value);
    bool empty();
    ~cola();
    void print();
};

template <class T>
void cola<T>::push(T value) {
    if (head == NULL) {
        head = new Node<T>(value);
        tail = head;
    } else {
        tail->next = new Node<T>(value);
        tail = tail->next;
    }
}

template <class T>
bool cola<T>::pop(T& value) {
    bool removed = false;
    value = 0;
    if (head) {
        value = head->value;
        removed = true;
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
    }
    return removed;
}

template <class T>
bool cola<T>::empty() {
    return !head;
}

template <class T>
cola<T>::~cola() {
    Node<T>* tmp;
    while (head) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <class T>
void cola<T>::print() {
    cout << "Head -> ";
    for (Node<T>* p = head; p; p = p->next) {
        cout << p->value << " -> ";
    }
    cout << "NULL\n";
}

int main() {
    cola<int> C;
    int v;
    for (int i = 1; i <= 10; i++) {
        C.push(i);
    }
    for (int i = 1; i <= 12; i++) {
        if (C.pop(v)) {
            cout << "El valor retirado " << v << endl;
        } else {
            cout << "Cola vacía\n";
        }
    }
}
