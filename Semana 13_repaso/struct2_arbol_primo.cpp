#include <iostream>
#include <vector>

using namespace std;

struct Nodo {
    int valor;
    Nodo* siguiente;

    Nodo(int val) : valor(val), siguiente(nullptr) {}
};

struct ImprimirFuntor {
    void operator()(const vector<Nodo*>& listas) const {
        for (const auto& inicio : listas) {
            Nodo* actual = inicio;
            while (actual != nullptr) {
                cout << actual->valor << " ";
                actual = actual->siguiente;
            }
            cout << endl;
        }
    }
};

bool esPrimo(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void generarListasPrimos(vector<Nodo*>& listas, int maximo) {
    for (int i = 2; i <= maximo; i++) {
        if (esPrimo(i)) {
            Nodo* inicio = new Nodo(i);
            Nodo* actual = inicio;

            for (int j = 2 * i; j <= maximo; j += i) {
                actual->siguiente = new Nodo(j);
                actual = actual->siguiente;
            }

            listas.push_back(inicio);
        }
    }
}

void liberarMemoria(vector<Nodo*>& listas) {
    for (const auto& inicio : listas) {
        Nodo* actual = inicio;
        while (actual != nullptr) {
            Nodo* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }
}

int main() {
    vector<Nodo*> listasPrimos;
    int maximo = 100;

    generarListasPrimos(listasPrimos, maximo);

    ImprimirFuntor imprimirFuntor;
    imprimirFuntor(listasPrimos);

    // Liberar memoria
    liberarMemoria(listasPrimos);

    return 0;
}
