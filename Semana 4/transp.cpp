#include <iostream>
using namespace std;

void transp(int (*p)[4]) {
    for (int* i = *p; i < *p + 4; ++i) {
        for (int* j = i + 1; j < *p + 4; ++j) {
            
            int temp = *(*(p + (i - *p)) + (j - *p));
            *(*(p + (i - *p)) + (j - *p)) = *(*(p + (j - *p)) + (i - *p));
            *(*(p + (j - *p)) + (i - *p)) = temp;
        }
    }
}

int main() {
    int A[4][4] = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 16}};

    transp(A);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
