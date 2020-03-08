#include<stdio.h>


int main(){
    int T;
    scanf("%d",&T);


    for(int i=0; i<T; i++){
        int A,B;
        scanf("%d %d", &A, &B);

        printf("Case #%d: %d + %d = %d\n",i+1,A,B,A+B);
    }

    return 0;
}