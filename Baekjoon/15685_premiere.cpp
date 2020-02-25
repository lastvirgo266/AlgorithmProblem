#include<stdio.h>
#include<math.h>

#define Y 0
#define X 1
#define START 2
#define GENER 3

int dir[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}};
int MAX = 100;
int board[100][100] = {{0,},};



void Test(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++)
            printf("%d",board[i][j]);
        
        printf("\n");
    }

    printf("\n\n");

}


void Curved(int y, int x, int start, int gener){
    int stack[10000];
    int top = 0;
    
    int nextY, nextX;

    board[y][x] = 1;

    nextY = y + dir[start][0];
    nextX = x + dir[start][1];

    board[nextY][nextX] = 1;
    stack[top] = start;

    for(int i=0; i<gener; i++){
        for(int i=top; i>=0; i--){
            if(stack[i]+1 >= 4){
                start = 0;
            }

            else{
                start = stack[i]+1;
            }
            
            top++;
            stack[top] = start;

            nextY = nextY + dir[start][0];
            nextX = nextX + dir[start][1];
            

            board[nextY][nextX] = 1;
            //printf("%d\n",i);
            // printf("%d %d %d\n\n",nextY, nextX,start);
            //     Test();
        }
        




    }

    //Test();

}


int Check(){
    int count = 0;

    for(int i=0; i<MAX-1; i++)
        for(int j=0; j<MAX-1; j++){
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