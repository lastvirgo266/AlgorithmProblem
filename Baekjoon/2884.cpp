#include<stdio.h>


int main(){
    int H;
    int M;

    scanf("%d",&H);
    scanf("%d",&M);


    if(M -45 < 0){
        if(H -1 < 0)
            H = 23;
        else
            H--;
        M  = (M + 60 - 45);
    }

    else
        M -=45;
    
    printf("%d %d",H, M);

    return 0;
}