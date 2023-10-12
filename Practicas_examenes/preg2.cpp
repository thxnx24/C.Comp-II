/* Qué realiza el siguiente codigo, suponiendo que 
A se encuentra en la dirección 100 y B en la direccion 200

a) Imprime las direcciones 112 y 212
b) Error de compilación
c) Imprime 3 6
d) Imprime 8 10
e) Imprime 7 10

Rpta.- 3 6
*/ 

#include <iostream>
using namespace std;

int main(){
    int a = 3, b = 6;
    int *p = &a, *q = &b;

    *p++;
    *q++;
    *p = *q;
    *p++;
    *q++;
    p = q;
    *p++;
    *q++;

    cout << a << " " << b;
    return 0;
}