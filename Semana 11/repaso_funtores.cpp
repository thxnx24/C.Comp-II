#include <iostream>
using namespace std;
/*
bool par(int n)
{
    return n % 2 == 0;
}

bool impar(int n)
{
    return n % 2 != 0;
}

void print_es (int a, bool(*p)(int))
{
    if (p(a))
    {
        cout << "Si cumple" << endl;
    }
    else
    {
        cout << "No cumple" << endl;
    }
}
*/

struct par 
{
    bool operator()(int n)
    {
        return n % 2 == 0;
    }
};

class impar 
{
    public:
        bool operator()(int n)
        {
            return n % 2 != 0;
        }
};
/*
template <class G>
void print_es (int a, G P)
{
    if (p(a))
    {
        cout << "Si cumple" << endl;
    }
    else
    {
        cout << "No cumple" << endl;
    }
}
*/
template <class T>
class cumple
{
    public:
        T op;
        void print_es1(int a)
        {
            if (op(a))
            {
                cout << "Si cumple" << endl;
            }
            else
            {
                cout << "No cumple" << endl;
            }
        }

        void print_es2(int a, T opr)
        {
            if (opr(a))
            {
                cout << "Si cumple" << endl;
            }
            else
            {
                cout << "No cumple" << endl;
            }
        }
};

int main()
{
    cumple <par> cp;
    cp.print_es1(20);
    cp.print_es2(20,par());
}