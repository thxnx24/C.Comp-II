#include <iostream>

void multiplicarMatrices(int *matrizA, int *matrizB, int *resultado) {
    int *ptrA = matrizA;
    int *ptrB = matrizB;
    int *ptrR = resultado;

    int i = 0;
    while (i < 9) {
        int j = 0;
        while (j < 9) {
            *(ptrR++) = 0;
            int *ptrA_temp = ptrA;
            int *ptrB_temp = ptrB;
            int k = 0;
            while (k < 3) {
                *(ptrR - 1) += (*(ptrA_temp++)) * (*(ptrB_temp));
                ptrB_temp += 3;
                k++;
            }
            ptrB++;
            j += 3;
        }
        ptrA += 9;
        i += 3;
    }
}

int main() {
    int A[3][3][3] = {
        {{2, 4, 6}, {3, 5, 7}, {8, 9, 1}},
        {{1, 2, 3}, {4, 5, 6}, {6, 9, 4}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
    };

    int *matrizA = &A[0][0][0];
    int *matrizB = &A[1][0][0];
    int *resultado = &A[2][0][0];

    multiplicarMatrices(matrizA, matrizB, resultado);

    std::cout << "El resultado de la multiplicación es:" << std::endl;
    int i = 0;
    while (i < 9) {
        int j = 0;
        while (j < 9) {
            std::cout << *(resultado++) << " ";
            j += 3;
        }
        std::cout << std::endl;
        i += 3;
    }

    return 0;
}
