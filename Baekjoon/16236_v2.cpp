#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

int N;
int shark_size=2;
int shark_needs = 0;
int fish[20][20] = {0,};

int move_direction[4][2] = { {-1, 0}, {0, -1}, {1,0}, {0,1} };
int eat_direction[4][2] = { {0,-1}, {-1 ,0}, {0,1}, {1,0} };


void Test(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%d ",fish[i][j]);
        printf("\n");
    }

    printf("\n\n\n");
}


//V2작성 30분 소모


int main(){

    int start_y, start_x;



    scanf("%d",&N);


    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            scanf("%d",&fish[i][j]);

            if(fish[i][j] == 9){
                fish[i][j] = 0;
                start_y = i;
                start_x = j;
            }
            
        }

    queue<pair <int, int> > shark_q;
    shark_q.push({start_y, start_x});
    int last_second = 0;
    shark_needs = shark_size;

    while(!shark_q.empty()){

        int visited[20][20] = {0, };

        pair< int, int > temp = shark_q.front();
        shark_q.pop();

        int shark_y = temp.first;
        int shark_x = temp.second;
        visited[shark_y][shark_x] = 1;

        //{ {y,x}, second }
        queue< pair< pair<int, int> , int> > fish_q;

        fish_q.push( {{shark_y, shark_x}, last_second});

        Test();

        while(!fish_q.empty()){
            pair<int, int> temp_pos = fish_q.front().first;
            int temp_second = fish_q.front().second;

            fish_q.pop();

        printf("%d %d\n",temp_second, shark_size);

        bool escape_ok = false;

            //Eat fish
            for(int i=0; i<4; i++){
                int go_y = temp_pos.first + eat_direction[i][0];
                int go_x = temp_pos.second + eat_direction[i][1];

                if(0<= go_y && go_y < N &&
                   0<= go_x && go_x < N &&
                   visited[go_y][go_x] == 0 &&
                   0 < fish[go_y][go_x] && 
                   fish[go_y][go_x] < shark_size){
                       visited[go_y][go_x] = 1;
                       pair < pair < int, int > , int > temp;
                       
                        shark_needs--;
                        if(shark_needs == 0){
                            shark_size++;
                            shark_needs = shark_size;
                        }

                        
                        fish[go_y][go_x] = 0;
                        shark_q.push({go_y, go_x});
                        last_second = temp_second+1;
                        escape_ok = true;
                        break;

                    }
            }

            if(escape_ok)
                break;

            //move shark
            for(int i=0; i<4; i++){
                int go_y = temp_pos.first + move_direction[i][0];
                int go_x = temp_pos.second + move_direction[i][1];

                if(0<= go_y && go_y <N &&
                   0<= go_x && go_x < N &&
                   visited[go_y][go_x] == 0 &&
                   fish[go_y][go_x] <= shark_size){
                       visited[go_y][go_x] = 1;
                       pair < pair < int, int > , int > temp; 
                       fish_q.push({ {go_y, go_x}, temp_second+1});

                    }

            }

        }//End While


    }


    printf("%d",last_second);


    return 0;

    



    
}