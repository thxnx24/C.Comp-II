#include <iostream>
#include <string>
using namespace std;


template <class T>
class funtor
{
    T x;
    public:
        funtor(T a): x(a) {};
        T operator() (T y)
        { 
            x = x + y; 
            return x;    
        }
};

template <class T, class O>
class opera
{
    public:
        void operator ()(T* a, O op)
        {
            *a = *(a + 1);
            *(a + 1) = op(*(a + 1));
        }
};

int main()
{
    int A[2] = {1,1};
    opera <int, funtor <int>> op;

    for (int i = 0; i < 10; i++)
    {
        cout << *A << " ";
        op(A, funtor <int>(*A));
    }
}