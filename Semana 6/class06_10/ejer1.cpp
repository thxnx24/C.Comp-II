#include <iostream>
using namespace std;

int main(){
    
    int ***A;
    A = new int **[3];

    for (int ***p = A; p < A + 3; p++)
    {
        *p = new int *[4];
        for ( int **q = *p; q < (*p) + 4; q++)
        {
            *q = new int [5];
        };
    };

    int x{0};

    for (int ***p = A; p < A + 3; p++)
    {
        x += 100;
        for (int **q = *p; q < (*p) + 4; q++)
        {
            x += 10;
            for (int *r = *q; r < (*q) + 5; r++)
            {
                x++;
                *r = x;
            };
        };
    };

    for (int ***p = A; p < A + 3; p++)
    {
        for (int **q = *p; q < (*p) + 4; q++)
        {
            for (int *r = *q; r < (*q) + 5; r++)
            {
                cout << *r << " ";
            };
            cout << endl;
        };
        cout << endl;
    };

    for (int ***p = A; p < A + 3; p++)
    {
        for (int **q = *p; q < (*p) + 4; q++)
        {
            delete []*q;
        };
        delete []*p;
    };
    delete []A;
    

    return 0;
}