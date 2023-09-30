#include <iostream>
using namespace std;

void multi_matriz(int (*p)[3][3])
{
    
};

int main()
{
    int A[3][3][3] = {{{2,4,6},{3,5,7},{8,9,1}},{{1,2,3},{4,5,6},{6,9,4}},{{0,0,0},{0,0,0},{0,0,0}}};

    for( int (*p)[3][3] = A; p < A + 3; p++){
        for (int (*q)[3] = *p; q < *(p + 1); q++){
            for (int *r = *q; r < *(q + 1); r++){
                cout << (*r) << " ";
            }
        }
    }
    return 0; 
};