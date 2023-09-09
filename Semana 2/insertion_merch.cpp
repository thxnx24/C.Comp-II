#include <iostream>
using namespace std;

void ordenar(int *ini, int *mid) 
{
    int *fin = mid + (mid - ini);
    while (ini < mid && mid < fin) {
        if (*ini > *mid) {
            int temp = *mid;
            for (int *p = mid; p > ini; --p) {
                *p = *(p - 1);
            }
            *ini = temp;
            ++mid;
        }
        ++ini;
    }
}

int main() {
    int A[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int n = sizeof(A) / sizeof(A[0]);

    int *ini = &A[0];
    int *mid = &A[5];

    cout << "Array desordenado:" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    ordenar(ini, mid);

    cout << "Array ordenado:" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
