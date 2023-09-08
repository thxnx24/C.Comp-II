#include <iostream>
using namespace std;

void orden(int *ini, int *mid)
{   
    int *fin = mid + (mid - ini);
    while (ini < mid && mid < fin)
        cout << "HOLA";
}



int main()
{
    int array[] = {8,11,15,17,18,35,3,5,48,72,80,100};
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

}