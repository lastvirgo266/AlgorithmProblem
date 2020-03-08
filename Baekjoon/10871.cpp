#include<stdio.h>


int main(){
    int N,X;

    scanf("%d %d",&N,&X);


    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);

        if(temp < X){
            printf("%d ",temp);
        }
    }

    return 0;

}