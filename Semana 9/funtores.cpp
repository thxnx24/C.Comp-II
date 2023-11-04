#include <iostream>
using namespace std;

struct Suma
{
    int operator()(int a,int b)
    {
        return a + b;
    }
};

struct Resta
{
    int operator()(int a, int b)
    {
        return a - b;
    }
};

void tabla1(int a, Suma op)
{
    for (int i = 1; i <= 10; i++)
    {
        cout << a << " = " << op(a,i);
    }
}

void tabla2(int a, Resta op)
{
    for (int i = 1; i <= 10; i++)
    {
        cout << i << " = " << op(a,i);
    }
}

template < class T >
void tabla3(int a, T op)
{
    for (int i = 1; i <= 10; i++)
    {
        cout << i<< " = " << op(a,i) << endl;
    } 
}

int main()
{
    //tabla1(10,Suma());
    //tabla2(10,Resta());
    Suma su;
    Resta res;
    tabla1(10, su);
    cout << "\n";
    tabla2(10, res);
    cout << "\n";
    tabla3(10,su);
    cout << "\n";
    tabla3(10,res);
    cout << "\n";
    tabla3(10,Suma());
    cout << "\n";
    tabla3(10,Resta());

}

