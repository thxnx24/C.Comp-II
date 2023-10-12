/*  Que realiza el sgte codigo 
a) Error de compilación
b) Imprime Hugo Paco Luis
c) Imprime H u g o P a c o L u i s
d) Imprime Hugo ugo go o Paco aco co o Luis uis is s
e) La ejecución puede dar resultados inesperados

Rota.- 
*/

#include <iostream>
using namespace std;

int main(){
    
    char Arr[3][5] = {"Hugo", "Paco", "Luis"};

    for (char *p = (char*)Arr; p <= &Arr[2][4]; p++){
        cout << *p << " ";
    }  
    
    return 0;
}