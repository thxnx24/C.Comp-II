#include <iostream>

void fibonacci(long *ArrEnt, int ArrTam) {
    if (ArrTam <= 2) {
        return;  // No se pueden generar más números si ya tienes los primeros dos.
    }

    long *ptr = ArrEnt + 2;  // Apuntar al tercer elemento del array.

    // Generamos el resto de la sucesión utilizando aritmética de punteros.
    for (int i = 2; i < ArrTam; i++) {
        long next = *(ptr - 2) + *(ptr - 1);
        *ptr = next;
        ptr++;
    }
}

int main() {
    int n;
    std::cout << "Ingrese el número de términos de la sucesión de Fibonacci: ";
    std::cin >> n;

    if (n < 2) {
        std::cout << "Se necesitan al menos 2 términos para generar la sucesión." << std::endl;
        return 1;
    }

    long *ArrEnt = new long[n];  // Asignación dinámica de memoria.

    ArrEnt[0] = 0;
    ArrEnt[1] = 1;

    fibonacci(ArrEnt, n);  // Llamada a la función para generar el resto de la sucesión.

    // Imprimir la sucesión de Fibonacci.
    for (int i = 0; i < n; i++) {
        std::cout << ArrEnt[i] << " ";
    }

    delete[] ArrEnt;  // Liberar la memoria asignada dinámicamente.

    return 0;
}
