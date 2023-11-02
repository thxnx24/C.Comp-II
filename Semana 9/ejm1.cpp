#include <iostream>
using namespace std;


class FUNCT
{
    int x;
    public:
        FUNCT(int a)
        {
            x = a;
        }
        int operator () (int b)
        {
            return x + b;
        }
};

int main()
{
    FUNCT obj(5);
    cout << obj(3);
}
