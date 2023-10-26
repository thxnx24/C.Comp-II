#include <iostream>
#include <string>
using namespace std;


template <class T>
struct nodo
{
    T valor;
    nodo <T> *next;
    nodo (T v, nodo < T > *n = NULL)
    {
        valor = v;
        next = n;
    }
};

template < class T >
struct pila
{
    nodo < T > * TOP = NULL;
    void push (T valor);
    bool POP (T &valor);
};
