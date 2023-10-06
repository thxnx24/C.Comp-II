#include <iostream>
using namespace std;

int main(){

    
    int ***A;
    A = new int **[3];

    for (int ***p = A; p < A + 3; p++){
        *p = new int *[4];
        for ( int **q = *p; q < (*p) + 4; q++){
            *q = new int [5];
        };
    };


    

    return 0;
}