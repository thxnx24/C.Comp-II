#include <iostream>
using namespace std;

void multiplicarMatrices(int (*matrizA)[3][3], int (*matrizB)[3][3], int (*resultado)[3][3]) {
    int (*ptrA)[3] = *matrizA;
    int (*ptrB)[3] = *matrizB;
    int (*ptrR)[3] = *resultado;

    for (; ptrA < (*matrizA + 3); ptrA++, ptrR++) {
        int *ptrA_row = *ptrA;
        int (*ptrB_col)[3] = *matrizB;

        for (int j = 0; j < 3; j++) {
            int *ptrA_elem = ptrA_row;
            int *ptrB_elem = *ptrB_col;
            int *ptrR_elem = *ptrR + j;

            for (int k = 0; k < 3; k++) {
                *ptrR_elem += *ptrA_elem * (*ptrB_elem);
                ptrA_elem++;
                ptrB_elem++;
            }
            ptrB_col++;
        }
    }
}

int main() {
    int A[3][3][3] = {
        {{2, 4, 6}, {3, 5, 7}, {8, 9, 1}},
        {{1, 2, 3}, {4, 5, 6}, {6, 9, 4}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
    };

    int (*matrizA)[3][3] = &A[0];
    int (*matrizB)[3][3] = &A[1];
    int (*resultado)[3][3] = &A[2];

    multiplicarMatrices(matrizA, matrizB, resultado);

    cout << "El resultado de la multiplicación es:" << endl;
    int (*ptrR)[3] = *resultado;

    for (; ptrR < (*resultado + 3); ptrR++) {
        int *ptrR_row = *ptrR;

        for (int j = 0; j < 3; j++) {
            cout << *ptrR_row << " ";
            ptrR_row++;
        }
        cout << endl;
    }

    return 0;
}
