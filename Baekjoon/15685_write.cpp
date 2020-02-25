#include<stdio.h>

int dir[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}};
int MAX = 100;
int board[101][101] = {{0,},};


void Curved(int y, int x, int start, int gener){
    int stack[1024];
    int top = 0;
    
    int nextY, nextX;

    board[y][x] = 1;

    nextY = y + dir[start][0];
    nextX = x + dir[start][1];

    board[nextY][nextX] = 1;
    stack[top] = start;

    for(int i=0; i<gener; i++){
        for(int i=top; i>=0; i--){

            start = ((stack[i] + 1)%4);

            top++;
            stack[top] = start;

            nextY = nextY + dir[start][0];
            nextX = nextX + dir[start][1];
            

            board[nextY][nextX] = 1;
        }
        




    }
}


int Check(){
    int count = 0;

    for(int i=0; i<MAX; i++) //여기에 문제가있었다!
        for(int j=0; j<MAX; j++){
            if(board[i][j] == 1 &&
               board[i][j+1] == 1 &&
               board[i+1][j] == 1 &&
               board[i+1][j+1] == 1)
               count++;
        }
    
    return count;
}




int main(){
    int N;

    scanf("%d",&N);

    for(int i=0; i<N; i++){
        int y,x,start,gener;

        scanf("%d",&x);
        scanf("%d",&y);
        scanf("%d",&start);
        scanf("%d",&gener);

        Curved(y,x,start,gener);

    }

    printf("%d",Check());
    return 0;
}