#include<queue>
#include<stdio.h>

#define DEPTH 0
#define POINT 1

#define LEFT 2
#define RIGHT 3

using namespace std;

typedef struct _bridge{
    int depth;
    int stick[3][2];
    int count;
}Bridge;

int ladder[571][11] = { {0,},};
int temp[571][11] = { {0,},};
int N,M,H;

void Test(){
    for(int i=1; i<=H; i++){
        for(int j=1; j<=N; j++)
            printf("%d ",temp[i][j]);
        
        printf("\n");
    }

    printf("\n\n");
}


int Simulation(){

    for(int i=1; i<=H; i++)
        for(int j=1; j<=N; j++){
            temp[i][j] = ladder[i][j];
        }
    

    for(int i=1; i<=N; i++){
        int current[2];
        current[DEPTH] = 1;
        current[POINT] = i;
        
        for(int j=1; j<=H; j++){
            if(temp[current[DEPTH]][current[POINT]] == 0){
                current[DEPTH] +=1;
            }

            else if(temp[current[DEPTH]][current[POINT]] == RIGHT){
                current[DEPTH] +=1;
                current[POINT] +=1;
            }

            else{
                current[DEPTH] +=1;
                current[POINT] -=1;        
            }
        }

        if(current[POINT] != i){
            return -1;
        }
    }

    return 1;

}


int CombinationThree(int depth, int start_point, int count){
    int result = 0;
    
    if(count == 4){
        result = Simulation();
        if(result == 1)
            return count;
        else
            return -1;
    }



    //Check the Correct whether stick
    for(int i=depth; i<=H; i++){
        for(int j = 1; j<N; j++){

        if(ladder[i][j] == 0 && ladder[i][j+1] == 0){
            ladder[i][j] = RIGHT;
            ladder[i][j+1] = LEFT;
            
            result = Simulation();

            ladder[i][j] = 0;
            ladder[i][j+1] = 0;

            if(result == 1)
                return count;
            
            

            }
        }

    }


    for(int i=depth; i<=H; i++){
        for(int j = 1; j<N; j++){
        if(ladder[i][j] == 0 && ladder[i][j+1] == 0){
            ladder[i][j] = RIGHT;
            ladder[i][j+1] = LEFT;
            
            result = CombinationThree(i,j, count+1);
            
            ladder[i][j] = 0;
            ladder[i][j+1] = 0;
            
            if(result >= 1)
                return result;
            }
        }

    }

    return -1;


}


int main(){
    scanf("%d",&N);
    scanf("%d",&M);
    scanf("%d",&H);



    for(int i=0; i<M; i++){
        int depth;
        int point;

        scanf("%d", &depth);
        scanf("%d", &point);

        ladder[depth][point] = RIGHT;
        ladder[depth][point+1] = LEFT;
    }

    int result = Simulation();

    if(result == 1)
        printf("0");

    else
        printf("%d",CombinationThree(1,1,1));

    return 0;

}