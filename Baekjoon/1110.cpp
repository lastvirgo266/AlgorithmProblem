#include<stdio.h>



int main(){
    int A;

    scanf("%d",&A);

    if(A < 10)
        A *= 10;

    int first = A/10;
    int second = A%10;

    int start = first;
    int end = second;
    int count = 0;


    do{
        int temp = second;
        second = (first+second) % 10;
        first = temp;
        count++;

    }while(start != first || end != second);
    

    printf("%d",count);

    return 0;
}