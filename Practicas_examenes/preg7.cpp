
#include <iostream>
using namespace std;

void merge(int *impar, int *par) 
{
    int *fin = par + (par - impar);
    while (impar < par && par < fin) {
        if (*impar > *par) {
            int temp = *par;
            for (int *p = par; p > impar; --p) {
                *p = *(p - 1);
            }
            *impar = temp;
            ++par;
        }
        ++impar;
    }
}

int main() {
    int A[] = {1, 3, 5, 7, 9, 11, 0, 2, 4, 6, 8, 10};
    int n = sizeof(A) / sizeof(A[0]);

    int *impar = A;
    int *par = A+(n/2);

    cout << "Array desordenado:" << endl;
    for (int *i = A; i < A+n; i++) {
        cout << *i << " ";
    }
    cout << endl;

    merge(impar, par);

    cout << "Array ordenado:" << endl;
    for (int *i = A; i < A+n; i++) {
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}