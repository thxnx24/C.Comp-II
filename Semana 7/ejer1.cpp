// Example program
#include <iostream>
#include <string>

using namespace std;

template <class t>
class nodo
{ 
    public:
    t valor;
    nodo<t>* next;
    nodo(t v, nodo<t> *n=NULL);
};

template <class t>
nodo<t>::nodo(t v, nodo<t> *n)
{
    valor=v;
    next=n;
}

int main()
{
    nodo<int> *head=NULL;
    nodo<int> *tmp;
    
    for(int i=1;i<=10;i++)
         head = new nodo<int>(i,head);
         
    cout<<"HEAD->";
    for(nodo<int> *p = head;p;p=p->next)
        cout<<p->valor<<"->";
    cout<<"NULL"<<endl;
    
    while(head)
    {
        tmp = head;
        head = head->next;
        cout<<"QDEP: "<<(*tmp).valor<<endl;
        delete tmp;
    }
        
}