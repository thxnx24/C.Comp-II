#include <iostream>
using namespace std;


int suma (int a, int b)
{
    return a + b;
}

int negativo (int a)
{
    return -a;
}

void oper1( int a, int b, int (*p)(int, int))
{
    cout << p(a,b);
}

void oper2(int a, int(*p)(int))
{
    cout << p(a);
}
int main()
{
    int x = 5, y = 6;
    oper1(5,6,suma);
    cout << "\n";
    oper2(5,negativo);
    //oper1(5,6,negativo);
    //oper2(5,6,suma);
}