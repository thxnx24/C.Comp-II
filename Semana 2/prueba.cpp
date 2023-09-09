#include <iostream>
using namespace std;

void orden(int* ini, int* mid) {
    int* fin = mid + (mid - ini);
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
    int A[] = { 1, 3, 5, 7, 9,11, 2, 4, 6, 8 , 10, 12};
    int* ini = A;
    orden(A, A + 6);

    for (int* p = A; p < A + 12; p++) {
        cout << *p << " ";
    }

    return 0;
}