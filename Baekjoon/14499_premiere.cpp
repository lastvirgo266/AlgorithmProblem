#include<stdio.h>
#define NORTH 1
#define SOUTH 4
#define EAST 2
#define WEST 3
#define UP 0
#define DOWN 5

using namespace std;


int dice[6] = {0,};
int now_X;
int now_Y;
int board[20][20] = { {0,}, };
int instruction[1000];

//주사위를 방향대로 움직임
void MoveDice(int direction){
    if(direction == 1 || direction == 2){

        //동쪽으로 회전
        if(direction == 1){
            int temp = dice[WEST];
            dice[WEST] = dice[DOWN];
            dice[DOWN] = dice[EAST];
            dice[EAST] = dice[UP];
            dice[UP] = temp;
        }

        else{
            int temp = dice[EAST];
            dice[EAST] = dice[DOWN];
            dice[DOWN] = dice[WEST];
            dice[WEST] = dice[UP];
            dice[UP] = temp;
        }

    }


    else{

        if(direction == 3){
            int temp = dice[SOUTH];
            dice[SOUTH] = dice[DOWN];
            dice[DOWN] = dice[NORTH];
            dice[NORTH] = dice[UP];
            dice[UP] = temp;
        }

        else{
            int temp = dice[NORTH];
            dice[NORTH] = dice[DOWN];
            dice[DOWN] = dice[SOUTH];
            dice[SOUTH] = dice[UP];
            dice[UP] = temp;
        }
    }


}

int main(){

    int N; //X
    int M; //Y

    int K;

    scanf("%d", &N);
    scanf("%d", &M);

    scanf("%d", &now_Y); //일부로 바꾼거임
    scanf("%d", &now_X);

    scanf("%d", &K);


    for(int i=0; i<N; i++){
        for(int j=0;j<M; j++){
            int temp;
            scanf("%d", &temp);
            board[i][j] = temp;
        }
    }


    for(int i=0; i<K; i++){
        int temp;
        scanf("%d", &temp);
        instruction[i] = temp;
    }


    //초기화 완료



    //실행
    for(int i=0; i<K; i++){
        int now_instruction = instruction[i];


        if(now_instruction == 1 && now_X + 1 <M){
                now_X++;
        }

        else if( now_instruction == 2 && now_X -1 >= 0){
            now_X--;
        }

        else if(now_instruction == 3 && now_Y -1 >= 0){
            now_Y--;
        }

        else if(now_instruction == 4 && now_Y + 1 < N){
            now_Y++;
        }

        else{
            continue;
        }

        MoveDice(now_instruction);

        int now_board = board[now_Y][now_X];

        if(now_board != 0){
            printf("%d\n", dice[UP]);
            dice[DOWN] = now_board;
            board[now_Y][now_X] = 0;
        }

        else{
            printf("%d\n",dice[UP]);
            board[now_Y][now_X] = dice[DOWN];
        }

        

    }




    return 0;



}   