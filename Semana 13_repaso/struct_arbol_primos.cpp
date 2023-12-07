#include <iostream>
#include <vector>

using namespace std;

struct Nodo {
    int valor;
    Nodo* siguiente;

    Nodo(int val) : valor(val), siguiente(nullptr) {}
};

struct primo_funtor {
    bool operator()(int num) const {
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
};

void imprime(const vector<Nodo*>& listas) {
    for (const auto& inicio : listas) {
        Nodo* actual = inicio;
        while (actual != nullptr) {
            cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }
}

void lista_primos(vector<Nodo*>& listas, int maximo, const primo_funtor& primo_funtor) {
    for (int i = 2; i <= maximo; i++) {
        if (primo_funtor(i)) {
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

    primo_funtor esPrimo;
    lista_primos(listasPrimos, maximo, esPrimo);
    imprime(listasPrimos);

    // Liberar memoria
    liberarMemoria(listasPrimos);

    return 0;
}
