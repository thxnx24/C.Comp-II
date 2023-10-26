#include <iostream>

using namespace std;

void fibonacci(long *ArrEnt, int ArrTam) {
    if (ArrTam <= 2) {
        return;  // No se pueden generar más números si ya tienes los primeros dos.
    }

    long *ptr = ArrEnt + 2;  // Apuntar al tercer elemento del array.

    long a = 0;
    long b = 1;

    ArrEnt[0] = a;
    ArrEnt[1] = b;

    // Generamos el resto de la sucesión utilizando aritmética de punteros.
    for (; ptr < ArrEnt + ArrTam; ptr++) {
        long next = a + b;
        *ptr = next;

        // Actualizamos los valores 'a' y 'b' para el siguiente cálculo.
        a = b;
        b = next;
    }
}

int main() {
    int n;
    cout << "Ingrese el número de términos de la sucesión de Fibonacci: ";
    cin >> n;

    if (n < 2) {
        cout << "Se necesitan al menos 2 términos para generar la sucesión." << endl;
        return 1;
    }

    long *ArrEnt = new long[n]; 

    fibonacci(ArrEnt, n);  

    for (long *ptr = ArrEnt; ptr < ArrEnt + n; ptr++) {
        cout << *ptr << " ";
    }

    delete[] ArrEnt;  

    return 0;
}
