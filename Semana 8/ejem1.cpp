#include <iostream>
#include <string>
using namespace std;

template < class T >
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
    bool Empty ();
    ~pila();
    void print();
};

template < class T >
void pila < T >::push (T valor)
{
    TOP = new nodo <T> (valor, TOP);
}

template < class T >
bool pila < T >::POP ( T &valor)
{
    bool saque = false;
    valor = 0;
    if (TOP)
    {
        valor = TOP -> valor;
        saque = true;
        nodo <T> *tmp = TOP;
        TOP = TOP -> next;
        delete tmp;
    }
    return saque;
}

template < class T >
bool pila < T >::Empty()
{
    return TOP;
}

template < class T >
pila <T>::~pila()
{
    nodo < T > *tmp;
    while (TOP)
    {
        tmp = TOP;
        TOP = TOP -> next;
        delete tmp;
    }
}

template < class T >
void pila < T >::print()
{
    cout << "TOP ->";
    for (nodo < T > *p = TOP; p; p = p -> next)
    {
        cout << p -> valor << " -> ";
    }
    cout << "NULL\n";
}

int main()
{
    pila < int > PL;
    int v;
    for (int i = 1 ; i <= 10 ; i++)
    {
        PL.push(i);
    }
    for (int i = 1 ; i <= 12 ; i++)
    {
        if ( PL.POP(v))
        {
            cout << "El valor retirado " << v << endl;
        }
        else
        {
            cout << "Pila vacia \n";
        }
    }
}