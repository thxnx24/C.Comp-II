#include <iostream>
using namespace std;

template <typename T, typename Functor>
class Nodo {
public:
    T data;
    Nodo<T, Functor>* next;
    Nodo<T, Functor>* prev;

    Nodo(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T, typename Functor>
class Lista_doble_enlazada {
private:
    Nodo<T, Functor>* head;

public:
    Lista_doble_enlazada() : head(nullptr) {}

    // Obtener el tamaño de la lista
    int size() const {
        if (!head) {
            return 0;
        }

        Nodo<T, Functor>* current = head;
        int count = 0;
        do {
            count++;
            current = current->next;
        } while (current != head);

        return count;
    }

    // Insertar un nuevo nodo en la lista
    void insertar(T value) {
        Nodo<T, Functor>* newNodo = new Nodo<T, Functor>(value);
        if (!head) {
            head = newNodo;
            head->next = head;
            head->prev = head;
        } else {
            Nodo<T, Functor>* last = head->prev;
            newNodo->next = head;
            newNodo->prev = last;
            head->prev = newNodo;
            last->next = newNodo;
        }
    }

    // Imprimir los elementos de la lista
    void imprime() const {
        if (!head) {
            cout << "La lista está vacía." << endl;
            return;
        }
        Nodo<T, Functor>* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    // Método de Josephus
    void josephus(int paso) {
        if (!head || size() == 1) {
            cout << "La lista está vacía o tiene solo un elemento." << endl;
            return;
        }

        // Verificar si 'paso' es válido
        if (paso >= size()) {
            cout << "El valor de 'paso' es mayor o igual al tamaño de la lista." << endl;
            return;
        }

        Nodo<T, Functor>* current = head;
        while (current->next != current) {
            // Mover 'paso-1' nodos hacia adelante
            for (int i = 0; i < paso - 1; ++i) {
                current = current->next;
            }

            // Imprimir y eliminar el nodo actual
            cout << "Eliminado: " << current->data << endl;
            Nodo<T, Functor>* temp = current->next;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            current = temp;
            imprime();
        }

        // Imprimir y eliminar el último nodo
        cout << "Eliminado: " << current->data << endl;
        delete current;

        // La lista está vacía después de Josephus
        head = nullptr;
    }
};

struct asc {
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

struct des {
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        return a > b;
    }
};

int main() {
    Lista_doble_enlazada<int, asc> lista_asc;
    lista_asc.insertar(5);
    lista_asc.insertar(2);
    lista_asc.insertar(8);
    lista_asc.insertar(1);
    lista_asc.insertar(3);
    lista_asc.insertar(4);
    lista_asc.insertar(7);

    cout << "Lista ascendente antes de ordenar: ";
    lista_asc.imprime();

    // Uso del método de Josephus en la lista ascendente
    cout << "\nEliminación Josephus en la lista ascendente:" << endl;
    lista_asc.josephus(2);  // Se elimina cada segundo elemento

    lista_asc.imprime();
    /*
    Lista_doble_enlazada<int, des> lista_des;
    lista_des.insertar(5);
    lista_des.insertar(2);
    lista_des.insertar(8);
    lista_des.insertar(1);
    lista_des.insertar(3);
    lista_des.insertar(4);
    lista_des.insertar(7);

    cout << "\nLista descendente antes de ordenar: ";
    lista_des.imprime();

    // Uso del método de Josephus en la lista descendente
    cout << "\nEliminación Josephus en la lista descendente:" << endl;
    lista_des.josephus(2);  // Se elimina cada tercer elemento

    lista_des.imprime();
    */
    return 0;
}
