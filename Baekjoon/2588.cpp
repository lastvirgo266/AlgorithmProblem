#include<stdio.h>


int main(){

    int A,B;

    scanf("%d %d", &A, &B);

    //초기화 완료

    int result= A*B;

    for(int i=0; i< 3; i++){
        printf("%d\n",A*(B%10));

        B /= 10;
    }

    printf("%d\n", result);


    return 0;



}