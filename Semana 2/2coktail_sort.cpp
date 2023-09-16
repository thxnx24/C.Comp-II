#include <iostream>
using namespace std;

void coktail(int *ini,int *fin ){
    while(ini<fin){
        for(int *brbja=ini;brbja<fin; brbja++){
            if(*brbja>*(brbja+1)){
                int temp=*(brbja+1);
                *(brbja+1)=*brbja;
                brbja++;
                *(brbja-1)=temp;
                brbja--;
            }
        }
        fin--;
        for(int *brbja=fin; brbja>ini;brbja--){
            if(*brbja<*(brbja-1)){
                int temp=*(brbja-1);
                *(brbja-1)=*brbja;
                brbja--;
                *(brbja+1)=temp;
                brbja++;
            }
        }
        ini++;
    }

}


int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    coktail(&a[0],&a[9]);
    for(int i = 0; i <= 9; ++i){
        cout << a[i] << " ";
    }
}