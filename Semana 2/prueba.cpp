#include <iostream>
using namespace std;

void orden(int* ini, int* mid) {
    int* fin = mid + (mid - ini - 1);
    while (ini < mid && mid < fin) {
        if (*ini > *mid) {
            swap(*ini, *mid);
        }
        ini++;
        for (int* temp = mid; temp < fin; temp++) {
            if (*temp < *ini) {
                swap(*temp, *ini);
                if (*ini == *mid)
                    mid++;
            }
        }
    }
}

int main() {
    int A[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8 , 10 };
    int* ini = A;
    orden(A, A + 5);

    for (int* p = A; p < A + 10; p++) {
        cout << *p << " ";
    }

    return 0;
}