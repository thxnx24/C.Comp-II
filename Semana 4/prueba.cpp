#include <iostream>
using namespace std;

void transp(int (*p)[4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            
            int *ptr1 = (*(p + i) + j);
            int *ptr2 = (*(p + j) + i);

            int temp = *ptr1;
            *ptr1 = *ptr2;
            *ptr2 = temp;
        }
    }
}

int main()
{
    int A[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    cout << "Matriz original:" << endl;
    for (int *ptr = &A[0][0]; ptr <= &A[3][3]; ptr++) {
        cout << *ptr << " ";
        if ((ptr - &A[0][0] + 1) % 4 == 0) {
            cout << endl;
        }
    }

    transp(A);

    cout << "Matriz transpuesta:" << endl;
    for (int *ptr = &A[0][0]; ptr <= &A[3][3]; ptr++) {
        cout << *ptr << " ";
        if ((ptr - &A[0][0] + 1) % 4 == 0) {
            cout << endl;
        }
    }

    return 0;
}
