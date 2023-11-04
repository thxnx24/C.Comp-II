#include <iostream>
using namespace std;

template < class P >
struct suma
{
    P operator()(P a, P b)
    {
        return a + b;
    }
};

template < class P >
struct resta
{
    P operator()(P a, P b)
    {
        return a - b;
    }
};

template < class T >
class oper
{
    public:
        T op;
};

template < class T , class O >
class oper2
{
    public:
        O op;
        T opp(T a, T b)
        {
            return op(a,b);
        }
};

int main()
{
    /*
    oper <suma> a;
    oper <resta> b;
    cout << a.op(5,3) << "\n";
    cout << b.op(5,3);
    */
    oper2 < int, suma < int >> su;
    oper2 < int , resta <int >> res;
    cout << su.op(5,6);
    cout << su.opp(5,6);
}