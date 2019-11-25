#include<stdio.h>

#define APPLE 3
#define Y 0
#define X 1
#define DIRECTION 2
#define WEIGHT 3

int board[100][100] ={0,};
//int direction_board[100][100] = {0,};
int snake[100][5]= {0,};
int snake_head = 0;
int max_X = 0;
int max_Y = 0;
int time = 0;


//디버그 : 처음에는 물체에 방향과 가중치를 줬음 --> 그러다보니 헤드가 이리저리 움직이면 결과가 꼬임 --> 그냥 선대의 위치를 물려받으면 됬음...



// --- test module ----//
void PrintBoard()
{
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
            printf("%d", board[i][j]);
    }

    printf("\n");
}

// void PrintDirectionBoard()
// {
//     for(int i=0; i<100; i++)
//     {
//         for(int j=0; j<100; j++)
//             printf("%d", direction_board[i][j]);
//     }

//     printf("\n");
// }
// --- test module END----//

void BoardMarking(int *snake)
{
    board[snake[Y]][snake[X]] = 1;
}


void BoardReset(int *snake)
{
    board[snake[Y]][snake[X]] = 0;
}

void SnakeInit()
{
    for(int i = snake_head; i >=0; i--)
    {
        snake[i][DIRECTION] = X;
        snake[i][WEIGHT] = 1;
    }
}


int MovingSnake(int direction, int count)
{
    int x_weight = 0;
    int y_weight = 0;

    if(direction == 'D' ){
        if (snake[snake_head][DIRECTION] == Y){
            x_weight = -1;
            snake[snake_head][DIRECTION] = X;
        }
        else{
            y_weight = -1;
            snake[snake_head][DIRECTION] = Y;
        }
    }

    else{
        if (snake[snake_head][DIRECTION] == Y){
            x_weight = 1;
            snake[snake_head][DIRECTION] = X;
        }
        else{
            y_weight = 1;
            snake[snake_head][DIRECTION] = X;
        }
    }


    
    snake[snake_head][WEIGHT] = x_weight + y_weight;

//여기에 카운트로 몇번 돌릴지 넣어야함
    for(int k=0; k<count; k++){
        int head_y = snake[snake_head][Y];
        int head_x = snake[snake_head][X];


        time++;

        //End
        if(head_y > max_Y || head_x > max_X){
            return -1;
        }


        //When Snake eats apple
        if(board[head_y+y_weight][head_x+x_weight] == APPLE)
        {
            snake_head++;
            snake[snake_head][Y] = head_y+ y_weight;
            snake[snake_head][X] = head_x + x_weight;
            snake[snake_head][DIRECTION] = snake[snake_head-1][DIRECTION];
            snake[snake_head][WEIGHT] = snake[snake_head-1][WEIGHT];

            BoardMarking(snake[snake_head]);
            continue;
        }

            BoardReset(snake[snake_head]);
            snake[i][ snake[i][DIRECTION] ] += snake[i][WEIGHT];
            BoardMarking(snake[i]);

    

        for(int i= snake_head; i >=0; i--){
            //기존에있던 가중치로 이동

            BoardReset(snake[i]);
            snake[i][ snake[i][DIRECTION] ] += snake[i][WEIGHT];
            BoardMarking(snake[i]);

            if(snake[i+1][DIRECTION] != snake[i][DIRECTION] && i < snake_head){
                snake[i][TURN_SIGNAL] = 1;
            }


            //턴 문제를 해결해야함
            //앞의 오브젝트로부터 다이렉션을 업데이트함
            if( i + 1 <= snake_head && snake[i+1][TURN_SIGNAL]  ){


            }
        
        }
    }




}



int main()
{
    int dircetion_list[100][2] = {0,};
    int N;
    scanf("%d",&N);

    max_X = N-1;
    max_Y = N-1;

    int K;
    scanf("%d", &K);

    for(int i=0; i<K; i++)
    {
        int y;
        int x;
        scanf("%d %d",&y, &x);
        board[y][x] = APPLE;
    }

    SnakeInit();


    int L;
    scanf("%d", &L);
    for(int i=0; i<L; i++)
    {
        int count;
        char direction;
        scanf("%d %c",&count, &direction);
        dircetion_list[i][0] = count;
        dircetion_list[i][1] = direction;
    }






}