#include<stdio.h>



int* FrontRobot(int direction){
    static int temp[2];

    if(direction == 0){
        temp[0] = -1;
        temp[1] =  0;
        return temp;
    }

    else if (direction == 1){
        temp[0] = 0;
        temp[1] = 1;
        return temp;
    }

    else if (direction == 2){
        temp[0] = 1;
        temp[1] = 0;
        return temp;
    }

    else{
        temp[0] = 0;
        temp[1] = -1;
        return temp;
    }
}


int* BackRobot(int direction){
    static int temp[2];

    if(direction == 0){
        temp[0] = 1;
        temp[1] = 0;
        return temp;
    }

    else if (direction == 1){
        temp[0] = 0;
        temp[1] = -1;
        return temp;
    }

    else if (direction == 2){
        temp[0] = -1;
        temp[1] = 0;
        return temp;
    }

    else{
        temp[0] = 0;
        temp[1] = 1;
        return temp;
    }
}


    int board[50][50];
    int N,M;

int main(){
    int direction = -1;
    int nowY, nowX;
    int count = 0;
    scanf("%d %d",&N,&M);
    scanf("%d %d %d", &nowY, &nowX, &direction);


    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            int temp;
            scanf("%d",&temp);
            board[i][j] = temp;
        }

    //초기화 완료

    int rotate = 0;

    while(direction != -1){
        int *temp_dir;
        int nextY, nextX;

        if(rotate == 4){
            temp_dir = BackRobot(direction);
            nextY = nowY + temp_dir[0];
            nextX = nowX + temp_dir[1];


            if(nextX >= 0 && nextX < M &&
               nextY >=0 && nextY < N && 
               board[nextY][nextX] != 1){
                   rotate = 0;
                   nowY = nextY;
                   nowX = nextX;
                   continue;
               }
            
            else{
                direction = -1;
                continue;
            }

        }

        if(board[nowY][nowX] == 0){
            board[nowY][nowX] = 3;
            count++;
        }

        if(direction - 1 < 0){
            direction = 3;
        }

        else{
            direction--;
        }


        temp_dir = FrontRobot(direction);


        nextY = nowY + temp_dir[0];
        nextX = nowX + temp_dir[1];


        
        if(nextX >= 0 && nextX < M &&
            nextY >=0 && nextY < N &&
            board[nextY][nextX] == 0){

                nowY = nextY;
                nowX = nextX;
                rotate = -1;

        }

        rotate++;

    }

    printf("%d",count);

    return 0;
}