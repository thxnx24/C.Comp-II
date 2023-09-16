#include <iostream>
using namespace std;

void coktail(int *ini,int *fin ){
    bool verifica = true;

    int a = 0;
    while(ini<fin && verifica){
        verifica = false;
        a++;
        cout << "-> " << a << endl;
        for(int *brbja=ini;brbja<fin; brbja++){
            if(*brbja>*(brbja+1)){
                int temp=*(brbja+1);
                *(brbja+1)=*brbja;
                brbja++;
                *(brbja-1)=temp;
                brbja--;
                verifica = true;
            }
        }
        fin--;
        if (!verifica)
            break;
            verifica = false;

        cout << " <- " << a << endl;
        for(int *brbja=fin; brbja>ini;brbja--){
            if(*brbja<*(brbja-1)){
                int temp=*(brbja-1);
                *(brbja-1)=*brbja;
                brbja--;
                *(brbja+1)=temp;
                brbja++;
                verifica = true;
            }
        }
        ini++;
    }

}


int main(){
    int a[10]={10,9,3,4,15,5,7,8,9,10};
    coktail(&a[0],&a[9]);
    for(int i = 0; i <= 9; ++i){
        cout << a[i] << " ";
    }
}