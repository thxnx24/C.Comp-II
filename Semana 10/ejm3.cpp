// Example program
#include <iostream>
#include <string>

using namespace std;

template<class T>
struct nodo
{
    T valor;
    nodo<T>* next;
    nodo(T x, nodo<T>* n=NULL):valor(x),next(n){};

};

template<class T>
class Iterator
{
    nodo<T>* it;
    public:

    void operator=(nodo<T>* n)
    {  it=n; }

    nodo<T>* operator++(int)
    { it = it->next;
      return  it;
    }

    int operator*()
    { return it->valor; }

    bool operator!()
    { return it; }
};

template<class T>
struct LE
{
    nodo<T> *head=NULL;
    typedef Iterator<T> it_LE;

    LE(int *A, int n=0)
    {
        nodo<T> *q;
        for(int *p=A; p<A+n; p++)
        {
            if(!head)
            {
                head= new nodo<T>(*p);
                q = head;
            }
            else
            {
                q->next= new nodo<T>(*p);
                q = q->next;
            }
        }
    }
};

int main()
{
    int A[10] = {11,9,25,30,28,16,8,74,21,55};
    LE<int> le(A,10);

    Iterator<int> p;
    for(p=le.head;!p;p++)
      {   
        cout<<*p<<" ";
      }
cout<<endl;
  LE<int>::it_LE q;
  for(q=le.head;!q;q++)
    {   
      cout<<*q<<" ";
    }

}