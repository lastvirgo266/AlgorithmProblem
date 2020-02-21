#include<stdio.h>


int main(){
    int num[3];
    int max_index = -99;

    scanf("%d",num);
    scanf("%d",num+1);
    scanf("%d",num+2);

    max_index = num[0];

    for(int i=0; i<3; i++){
        if(num[i] > num[max_index]){
            int temp = max_index;
            max_index = i;

        }
    }

    

    



    return 0;
    

}