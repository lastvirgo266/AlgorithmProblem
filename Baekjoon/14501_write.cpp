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

        memoi[i] = temp_2;

    }


    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
           if(i >= j + table[j][DATE]){
               int result = memoi[j] + table[i][VALUE];
               memoi[i] = memoi[i] > result ? memoi[i] : result;
           }
        }
        
    }
 
    for (int i = 0; i < N; i++) {
        if (i + table[i][DATE] <= N) {
            if (max < memoi[i]) {
                max = memoi[i];
            }
        }
    }

    printf("%d", max); 

    return 0;
}