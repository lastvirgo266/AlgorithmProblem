#include<stdio.h>
#include<queue>
using namespace std;
int decayed[8][8] = {0,};
int board[8][8] = {0,};
int weight[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0}};
int N,M;

typedef struct _point{
    int y, x;
}Point;


int BFS(){

    queue<Point> que;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(decayed[i][j] == 2){
                Point point;
                point.y = i;
                point.x = j;
                que.push(point);
            }
        }

    
    while(!que.empty()){
        Point temp = que.front();
        que.pop();

        for(int i=0; i<4; i++){
            int nextY = temp.y + weight[i][0];
            int nextX = temp.x + weight[i][1];

            if(nextY < N &&
               nextX < M &&
               nextX >= 0 &&
               nextY >= 0 &&
               decayed[nextY][nextX] == 0){
                   decayed[nextY][nextX] = 2;
                   Point point;
                   point.x = nextX;
                   point.y = nextY;
                   que.push(point);
               }
        }

    }

    int count =0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(decayed[i][j] == 0){
                count++;
            }
        }
    
    return count;

}


void Experiment(){
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            decayed[i][j] = board[i][j];
}


int MakeWall(int current){
    if(current == 3){
        Experiment();
        return BFS();
    }

    int result = 0;
    int max = -99;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(board[i][j] == 0){
                board[i][j] = 1;
                result = MakeWall(current + 1);
                board[i][j] = 0;
                max = max > result ? max : result;
            }
        }

    return max;


}





int main(){

    queue<Point> que;

    scanf("%d %d",&N, &M);


    for(int i = 0; i<N; i++)
        for(int j =0; j<M; j++){
            int temp = 0;
            scanf("%d",&temp);
            board[i][j] = temp;
        }

    
    
    
    //초기화 완료
    int max = -99;


    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            int result = 0;
            if(board[i][j] == 0){
                board[i][j] =1;
                result = MakeWall(1);
                board[i][j] = 0;
                max = max > result ? max : result;
            }
        }

    

    printf("%d",max);



    return 0;
}