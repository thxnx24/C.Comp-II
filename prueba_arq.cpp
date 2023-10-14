#include <iostream>
#include <vector>

int main() {
    int grado;

    std::cout << "Ingrese el grado del polinomio: ";
    std::cin >> grado;

    // Verificar que el grado es no negativo
    if (grado < 0) {
        std::cout << "El grado del polinomio debe ser no negativo." << std::endl;
        return 1;
    }

    // Crear un vector para almacenar los coeficientes
    std::vector<double> coeficientes(grado + 1);

    // Solicitar los coeficientes
    for (int i = 0; i <= grado; ++i) {
        std::cout << "Ingrese el coeficiente para x^" << i << ": ";
        std::cin >> coeficientes[i];
    }

    // Solicitar el valor de x
    double x;
    std::cout << "Ingrese el valor de x: ";
    std::cin >> x;

    // Calcular el valor del polinomio en x
    double resultado = 0;
    double potencia_x = 1; // Inicializar con x^0

    for (int i = 0; i <= grado; ++i) {
        resultado += coeficientes[i] * potencia_x;
        potencia_x *= x;
    }

    // Imprimir el resultado
    std::cout << "El valor del polinomio en x=" << x << " es: " << resultado << std::endl;

    return 0;
}
