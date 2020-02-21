#include<stdio.h>


int main(){
    int num[3];

    scanf("%d",num);
    scanf("%d",num+1);
    scanf("%d",num+2);


    for(int i=0; i<2; i++){
        if(num[i+1] < num[i]){
            int temp = num[i];
            num[i] = num[i+1];
            num[i+1] = temp;
        }
    }

    if(num[1] > num[0])
        printf("%d",num[1]);
    else
        printf("%d",num[0]);


    return 0;
    

}