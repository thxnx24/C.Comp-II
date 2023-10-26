/* Qué realiza el sgte código, suponiendo que el array A inicia en la direccion 200

a) Imprime 1 2 3 4 5 6
b) Error de compilación
c) Imprime 200 201 202 203 204 205
d) Imprime 200 204 208 212 216 220

Rpta.- Imprime 1 2 3 4
*/ 

#include <iostream>
using namespace std;

int main(){
    int a[2][3] = {{1,2,3},{4,5,6}};

    for (int *i = *a; i < *a + 6; i++){
        cout << *i << " ";
    }

    return 0;
}