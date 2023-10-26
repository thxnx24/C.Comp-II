#include <iostream>
using namespace std;

void fibonacci(long *ArrEnt, int ArrTam) {
    if (ArrTam <= 2) {
        return;  // No se pueden generar más números si ya tienes los primeros dos.
    }

    long *ptr = ArrEnt + 2;  // Apuntar al tercer elemento del array.
    long *end = ArrEnt + ArrTam;  // Puntero al final del array.

    long *prev1 = ArrEnt + 1;  // Apuntar al segundo elemento del array.
    long *prev2 = ArrEnt;  // Apuntar al primer elemento del array.

    // Generamos el resto de la sucesión utilizando aritmética de punteros.
    while (ptr < end) {
        *ptr = *prev2 + *prev1;
        ptr++;
        prev1++;
        prev2++;
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

    long *ArrEnt = new long[n];  // Asignación dinámica de memoria.
    ArrEnt[0] = 0;
    ArrEnt[1] = 1;

    fibonacci(ArrEnt, n);  // Llamada a la función para generar el resto de la sucesión.

    // Imprimir la sucesión de Fibonacci.
    for(long *p = ArrEnt; p < ArrEnt+n; p++){
        cout<< *p << " ";
    }
    delete[] ArrEnt;  // Liberar la memoria asignada dinámicamente.

    return 0;
}
