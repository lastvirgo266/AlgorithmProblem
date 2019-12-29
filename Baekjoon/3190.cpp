#include<stdio.h>

#define APPLE 3
#define Y 0
#define X 1
#define LEFT -1
#define RIGHT 1
#define DOWN 1
#define UP -1

int board[100][100] ={0,};
//int direction_board[100][100] = {0,};
int snake[100][2]= {0,};
int snake_head = 0;
int snake_head_directoin = 0;
int snake_head_weight = 0;
int max_X = 0;
int max_Y = 0;
int time = 0;


//디버그 : 처음에는 물체에 방향과 가중치를 줬음 --> 그러다보니 헤드가 이리저리 움직이면 결과가 꼬임 --> 그냥 선대의 위치를 물려받으면 됬음...



// --- test module ----//
void PrintBoard()
{

    printf("%d\n %d\n", snake_head_directoin, snake_head_weight);
    for(int i=0; i<=max_X; i++)
    {
        for(int j=0; j<=max_Y; j++)
            printf("%d", board[i][j]);

        printf("\n");
    }

    printf("\n");
}
//----test module END----//



void BoardMarking(int *snake)
{
    board[snake[Y]][snake[X]] = 1;
}




void BoardReset(int *snake)
{
    board[snake[Y]][snake[X]] = 0;
}



int MovingSnake(int count, int direction)
{
    int x_weight = 0;
    int y_weight = 0;

    if(direction == 'D' ){
        if (snake_head_directoin == Y){
            if(snake_head_weight == UP){
                x_weight = 1;
                snake_head_directoin = X;
                snake_head_weight = RIGHT;
            }

            else{
                x_weight = 1;
                snake_head_directoin = X;
                snake_head_weight = RIGHT;
            }
        
        }


        else{
            if(snake_head_weight == LEFT){
                y_weight = -1;
                snake_head_directoin = Y;
                snake_head_weight = UP;
            }

            else{
                y_weight = 1;
                snake_head_directoin = Y;
                snake_head_weight = DOWN;
            }
        }
    }



    else{
        if (snake_head_directoin == Y){

            if(snake_head_weight == UP){
            x_weight = -1;
            snake_head_directoin = X;
            snake_head_weight = LEFT;
            }

            else{
            x_weight = 1;
            snake_head_directoin = X;
            snake_head_weight = RIGHT;       
            }
        }

        else{
            if(snake_head_weight == LEFT){
                y_weight = 1;
                snake_head_directoin = Y;
                snake_head_weight = DOWN;
            }

            else{
                y_weight = -1;
                snake_head_directoin = Y;
                snake_head_weight = UP;           
            }
        }
    }

    //여기에 카운트로 몇번 돌릴지 넣어야함
    for(int k=0; k<count; k++){
        
        //time up
        time++;

        int head_y = snake[snake_head][Y];
        int head_x = snake[snake_head][X];


        //End
        if(head_y+y_weight > max_Y || head_x+x_weight > max_X ||
           head_y+y_weight < 0 || head_x+x_weight < 0){
            return -1;
        }

        if(board[head_y+y_weight][head_x+x_weight] == 1){
            return -1;
        }


        //When Snake eats apple
        if(board[head_y+y_weight][head_x+x_weight] == APPLE)
        {
            snake_head++;
            snake[snake_head][Y] = head_y+ y_weight;
            snake[snake_head][X] = head_x + x_weight;

            BoardMarking(snake[snake_head]);
            continue;
        }

        //make head information
        int front_Y = snake[snake_head][Y];
        int front_X = snake[snake_head][X];

        //move head
        BoardReset(snake[snake_head]);
        snake[snake_head][Y] += y_weight;
        snake[snake_head][X] += x_weight;
        BoardMarking(snake[snake_head]);

        //Test
        PrintBoard();



        if(snake_head -1 >= 0){
            for(int i = snake_head-1; i >=0; i--){

                //make now information
                int now_Y = snake[i][Y];
                int now_X = snake[i][X];
                
                //load front information
                snake[i][Y] = front_Y;
                snake[i][X] = front_X;

                //move to front
                BoardReset(snake[i]);
                BoardMarking(snake[i]);

                //swap information
                front_Y = now_Y;
                front_X = now_X;
            
            }
        }
    }




}



int main()
{
    int direction_list[100][2] = {0,};
    int N;
    scanf("%d",&N);

    max_X = N-1;
    max_Y = N-1;

    snake_head = 0;
    snake[snake_head][Y]=0;
    snake[snake_head][X]=0;
    snake_head_directoin = X;
    snake_head_weight = RIGHT;
    BoardMarking(snake[snake_head]);

    int K;
    scanf("%d", &K);

    for(int i=0; i<K; i++)
    {
        int y;
        int x;
        scanf("%d %d",&y, &x);
        board[y][x] = APPLE;
    }


    int L;
    scanf("%d", &L);
    for(int i=0; i<L; i++)
    {
        int count;
        char direction;
        scanf("%d %c",&count, &direction);
        direction_list[i][0] = count;
        direction_list[i][1] = direction;
    }

    for(int i=0; i<L; i++){
       int result =  MovingSnake(direction_list[i][0], direction_list[i][1]);
       PrintBoard();
    
        if(result == -1){
            printf("%d",time);
            return 0;
        }
    }






}