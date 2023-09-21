#include <iostream>
using namespace std;

void transp (int (*p)[4]    )
{
    for(int (*i) = *p; i < *(p + 1); ++i){
        for (int (*j) = i; j < i; ++j){
            int *ptr1 = (*(p + i) + j);
            int *ptr2 =
        }
    }
};

int main()
{
    int A[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};


}