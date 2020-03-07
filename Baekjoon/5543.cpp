#include<stdio.h>


int main(){
    int burger[3]={0,};
    int drink[2]={0,};

    int burger_min = 99999999;
    int drink_min = 99999999;


    for(int i=0; i<3; i++){
        scanf("%d",&burger[i]);
        burger_min = burger_min < burger[i] ? burger_min : burger[i];
    }


    for(int i=0; i<2; i++){
        scanf("%d",&drink[i]);
        drink_min = drink_min < drink[i] ? drink_min : drink[i];
    }



    printf("%d", burger_min + drink_min - 50);


    return 0;



}