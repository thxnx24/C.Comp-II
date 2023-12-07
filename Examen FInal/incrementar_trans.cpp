#include <iostream>
using namespace std;

struct increment{
    int valor;
    increment(int n):valor(n) {};
    int operator() (int a) {
        return(valor + a);
    }
};

void transform(int* ini, int* fin, increment c){
    for (int* d = ini; d < fin; d++)
    {
        *d = c(*d);
    }
}

int main()
{
    int arr [] = {1,2,3,4,5};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int to_add = 5;

    transform (arr, arr +n, increment(to_add));

    for (int i = 0; i < n; i++)
    {
        cout << arr [i] << " ";
    }
}