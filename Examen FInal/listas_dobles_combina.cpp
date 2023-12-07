#include <iostream>
#include <string>
using namespace std;

template <class T>
struct Nodo {
    T valor;
    Nodo<T> *next;
    Nodo<T> *prev;
    Nodo(T v, Nodo<T> *n = nullptr, Nodo<T> *p = nullptr) {
        valor = v;
        next = n;
        prev = p;
    }
};

template <class T>
class lista_doble_enl {
  public:
    Nodo<T> *head = nullptr;
    Nodo<T> *tail = nullptr;
    void agregar(T valor);
    void eliminar(T valor);
    bool buscar(T valor, Nodo<T> *&Pos);
    ~lista_doble_enl();
    void imprimir();
};

template <class T>
bool lista_doble_enl<T>::buscar(T valor, Nodo<T> *&Pos) {
    Pos = nullptr;
    Nodo<T> *p = head;

    for (; p && p->valor < valor; Pos = p, p = p->next);
    return (p && p->valor == valor);
}

template <class T>
void lista_doble_enl<T>::agregar(T valor) {
    Nodo<T> *Pos;
    if (!buscar(valor, Pos)) {
        Nodo<T> *newNode = new Nodo<T>(valor);
        if (!Pos) {
            newNode->next = head;
            newNode->prev = nullptr;
            if (head)
                head->prev = newNode;
            head = newNode;
            if (!tail)
                tail = newNode;
        } else {
            newNode->next = Pos->next;
            newNode->prev = Pos;
            if (Pos->next)
                Pos->next->prev = newNode;
            Pos->next = newNode;
            if (tail == Pos)
                tail = newNode;
        }
    }
}

template <class T>
void lista_doble_enl<T>::eliminar(T valor) {
    Nodo<T> *Pos, *tmp;
    if (buscar(valor, Pos)) {
        if (!Pos) {
            tmp = head;
            head = head->next;
            if (head)
                head->prev = nullptr;
            delete tmp;
        } else {
            tmp = Pos->next;
            Pos->next = Pos->next->next;
            if (Pos->next)
                Pos->next->prev = Pos;
            if (tail == tmp)
                tail = Pos;
            delete tmp;
        }
    }
}

template <class T>
void lista_doble_enl<T>::imprimir() {
    Nodo<T> *act = head;
    while (act != nullptr) {
        cout << act->valor << " ";
        act = act->next;
    }
}

template <class T>
lista_doble_enl<T>::~lista_doble_enl() {
    Nodo<T> *actual = head;
    while (actual != nullptr) {
        Nodo<T> *front = actual->next;
        delete actual;
        actual = front;
    }
}

template <class T>
void merge(lista_doble_enl<T> &h1, lista_doble_enl<T> &h2) {
    Nodo<T> *p = h1.head;
    Nodo<T> *q = h2.head;
    Nodo<T> *r = nullptr;

    if (p && q) {
        if (p->valor < q->valor) {
            r = p;
            p = p->next;
        } else {
            r = q;
            q = q->next;
        }

        h1.head = r;

        while (p && q) {
            if (p->valor < q->valor) {
                r->next = p;
                r->next->prev = r;
                r = p;
                p = p->next;
            } else {
                r->next = q;
                r->next->prev = r;
                r = q;
                q = q->next;
            }
        }

        if (p) {
            r->next = p;
            r->next->prev = r;
        } else if (q) {
            r->next = q;
            r->next->prev = r;
        }

        h2.head = nullptr;
        h2.tail = nullptr;
    }
}

int main() {
    lista_doble_enl<int> h1, h2;

    h1.agregar(1);
    h1.agregar(9);
    h1.agregar(5);
    h1.agregar(3);
    h1.agregar(11);
    h2.agregar(2);
    h2.agregar(4);
    h2.agregar(6);
    h2.agregar(7);

    cout << "h1: ";
    h1.imprimir();
    cout << endl;

    cout << "h2: ";
    h2.imprimir();
    cout << endl;

    merge(h1, h2);

    cout << "Lista Fusionada h1: ";
    h1.imprimir();
    cout << endl;

    cout << "Lista Fusionada h2: ";
    h2.imprimir();
    cout << endl;

    return 0;
}
