//Recorrido puntero y arrays 3D"

#include <iostream>
using namespace std;

void print1(int A[][2][5],int tam)
{
   cout<<"Recorrido dentro de print1"<<endl;
  for(int (*p)[2][5] = A;p<A+tam; p++)
  {
    cout<<*p<<" -> "<< **p <<" -> "<<***p << endl;
    for(int (*q)[5] = *p; q < *(p+1);q++)
    {
      cout<<" "<<*q<<" -> "<<**q<<endl;
      cout<<"   ";
      for(int *r = *q; r < *(q+1); r++)
        cout<<*r<<" ";
      cout<<endl;
    }
    cout<<endl;
  } 
}

void print2(int (*A)[2][5],int tam)
{
   cout<<"Recorrido dentro de print2"<<endl;
  for(int (*p)[2][5] = A;p<A+tam; p++)
  {
    cout<<*p<<" -> "<< **p <<" -> "<<***p << endl;
    for(int (*q)[5] = *p; q < *(p+1);q++)
    {
      cout<<" "<<*q<<" -> "<<**q<<endl;
      cout<<"   ";
      for(int *r = *q; r < *(q+1); r++)
        cout<<*r<<" ";
      cout<<endl;
    }
    cout<<endl;
  } 
}

int main() {
  int A[2][2][5] = {{{11,12,13,14,15},{16,17,18,19,10}},
                {{21,22,23,24,25},{26,27,28,29,20}}};
  
  cout<<"Recorrido dentro de main"<<endl;
  for(int (*p)[2][5] = A;p<A+2; p++)
  {
    cout<<*p<<" -> "<< **p <<" -> "<<***p << endl;
  }
}