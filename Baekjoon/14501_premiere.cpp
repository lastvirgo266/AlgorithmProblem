#include<stdio.h>

#define DATE 0
#define VALUE 1

using namespace std;


int main(){
    int memoi[16] = {0,};
    int table[15][2] = { {0,},};
    int max = 0;

    int N;
    scanf("%d", &N);


    for(int i=0; i<N; i++){
        int temp_1;
        int temp_2;

        scanf("%d", &temp_1);
        scanf("%d", &temp_2);

        table[i][DATE] = temp_1;
        table[i][VALUE] = temp_2;

    }


    for(int i=0; i<N; i++){
        int weight = 0;

        if(table[i][DATE] == 1){
            weight = table[i][VALUE];
        }

        for(int j=0; j<i; j++){
           if(i >= j + table[j][DATE]){
               int jump = j + table[j][DATE];
               int result = memoi[j] + table[j][VALUE];
               memoi[jump] = memoi[jump] > result ? memoi[jump] : result;
               max = max > memoi[jump] ? max : memoi[jump];
           }
        }

        //Test
        printf("%d %d\n",i, memoi[i]);
        
    }
        printf("%d %d\n",N-1, memoi[N]);

    if(table[N-1][DATE] == 1){
       memoi[N-1] += table[N-1][VALUE];
        max = max > memoi[N-1] ? max : memoi[N-1];
    }


    printf("%d", max); 

    return 0;
}