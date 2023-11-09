// Example program
#include <iostream>
#include <string>

using namespace std;

struct nodo
{
    int valor;
    nodo* next;
    nodo(int x, nodo* n=NULL):valor(x),next(n){};
   
};

struct LE
{
    nodo *head=NULL;
    LE(int *A, int n=0)
    {
        nodo *q;
        for(int *p=A; p<A+n; p++)
        {
            if(!head)
            {
                head= new nodo(*p);
                q = head;
            }
            else
            {
                q->next= new nodo(*p);
                q = q->next;
            }
        }
    }
};

int main()
{
    int A[10] = {11,9,25,30,28,16,8,74,21,55};
    LE le(A,10);
}