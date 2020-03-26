#include<stdio.h>
#define MAX 99999999


//초안 30분
//테스트 30분 못풀었음


int y=1;
int x=1;
int N;
int d1=1;
int d2=1;
int total=0;

int temp_map[21][21] {0,};
int map[21][21]={0,};
int result_min = MAX;

void Five() {
	for (int i = 0; i <= d1; i++) {
	    temp_map[y + i][x - i] = 5;
		temp_map[y + d2 + i][x + d2 - i] = 5;
	}

	for (int i = 0; i <= d2; i++) {
		temp_map[y + i][x + i] = 5;
		temp_map[y + d1 + i][x - d1 + i] = 5;
	}


}


void Solved(){

    int person[6] = {0,};
    int max = 0;
    int min = MAX;

    //First
    for(int i=1; i<y+d1; i++)
        for(int j=1; j<=x; j++){
            if(temp_map[i][j] == 5)
                break;

            person[1] += map[i][j];
            temp_map[i][j] = 1;
        }

    max = max > person[1] ? max : person[1];
    min = min < person[1] ? min : person[1];
    
    //Second
    for(int i=1; i<=y+d2; i++)
        for(int j=N; j> x; j--){
            if(temp_map[i][j] == 5)
                break;
            person[2] += map[i][j];
            temp_map[i][j] = 2;
        }

    max = max > person[2] ? max : person[2];
    min = min < person[2] ? min : person[2];

    //Third
    for(int i=y+d1; i<=N; i++)
        for(int j=1; j<x-d1+d2; j++){
            if(temp_map[i][j] == 5)
                break;
            person[3] += map[i][j];
            temp_map[i][j] = 3;
        }
    max = max > person[3] ? max : person[3];
    min = min < person[3] ? min : person[3];

    //Fourth
    for(int i=y+d2+1; i<=N; i++)
        for(int j=N; j>=x-d1+d2; j--){
            if(temp_map[i][j] == 5)
                break;
            person[4] += map[i][j];
            temp_map[i][j] = 4;
        }

    max = max > person[4] ? max : person[4];
    min = min < person[4] ? min : person[4];

    person[5] = total - (person[1] + person[2] + person[3] + person[4]);

    max = max > person[5] ? max : person[5];
    min = min < person[5] ? min : person[5];

    result_min = result_min < max-min ? result_min : max-min;


    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            temp_map[i][j] = 0;


    return;


}


void DFS(){
    for(int temp_d1=1; temp_d1<N; temp_d1++){
        for(int temp_d2=1; temp_d2<N; temp_d2++){
            for(int temp_y=1; temp_y<=N; temp_y++){
                for(int temp_x= 1;temp_x<=N; temp_x++ ){
                    if( temp_d1 >=1 && temp_d2 >=1 &&
                       temp_y + temp_d1 + temp_d2 <= N &&
                       1 <= temp_x - temp_d1 && temp_x + temp_d2 <=N){
                        y = temp_y;
                        x = temp_x;
                        d1 = temp_d1;
                        d2 = temp_d2;
                        Five();
                        Solved();
                    }
                }
            }
        }
    }

}

int main(){

    scanf("%d",&N);


    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++){
            scanf("%d",&map[i][j]);
            total += map[i][j];
        }

    DFS();

    printf("%d",result_min);


    return 0;

}