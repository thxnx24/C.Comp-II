/* Que realiza el sgte codigo
a) Error de compilacion
b) Imprime 15 15
c) Imprime 4 4
d) Imprime 15 4
e) La ejecución puede dar resultados inesperados

Rpta.- 15 y 4
*/

#include <iostream>
using namespace std;

void funcion(char A[][5]){
    cout << sizeof(A);
}

int main(){
    char Arr[][5] = {"Hugo","Paco","Luis"};

    cout << sizeof(Arr) << " ";
    funcion(Arr);

    return 0;
}