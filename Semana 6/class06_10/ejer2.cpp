//Estructura de nodos

#include <iostream>
using namespace std;

struct nodo
{
    int valor;
    nodo *next;
};

main() 
{
    nodo *head;
    head = new nodo;
    (*head).valor = 1;
    head -> valor = 1;
    head -> next = new nodo;
    head -> next -> valor = 2;
    head -> next -> next = new nodo;
    head -> next -> next -> valor = 3;
    head -> next -> next -> next = nullptr;
}