#include<stdio.h>
#include<queue>
#include<vector>
#define WHITE 0
#define RED 1
#define BLUE 2
using namespace std;

//초안 작성 40분
//테스트 40분
// 시간초과
int map[12][12] = {0,};
int N,K;

typedef struct _chessP{
    int number;
    int y,x;
    int direction[2];
}Chess;

vector< vector< vector < Chess > > > map_info;
vector< Chess > arr_chess;


void Test(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ",map_info[i][j].size());
        }

        printf("\n");
    }

    printf("\n\n");
}

int CheckMap(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(map_info[i][j].size() >= 4)
                return 1;

    return 0;

}


void DirectionParsing(Chess &chess, int direction){
    if(direction == 1){
        chess.direction[0] = 0;
        chess.direction[1] = 1;
    }

    else if(direction == 2){
        chess.direction[0] = 0;
        chess.direction[1] = -1;
    }

    else if(direction == 3){
        chess.direction[0] = -1;
        chess.direction[1] = 0;
    }

    else{
        chess.direction[0] = 1;
        chess.direction[1] = 0;
    }
}

int main(){

    scanf("%d %d",&N, &K);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            scanf("%d",&map[i][j]);
        }

    
    map_info.resize(N);
    for(int i=0; i<N; i++){
        map_info[i].resize(N);
    }



    for(int i=0; i<K; i++){
        Chess temp;
        int direction;
        scanf("%d %d %d", &temp.y, &temp.x, &direction);
        
        //(1,1) --> (0,0) axis
        temp.y -=1;
        temp.x -=1;
        DirectionParsing(temp, direction);
        temp.number = i;
        map_info[temp.y][temp.x].push_back(temp);
        arr_chess.push_back(temp);
    }

    int cur_number = 0;

    int count = 1;

    int queue_count =0;


    while(1){

        //printf("%d\n",count);

        queue_count++;

        printf("%d\n",cur_number);

        Chess temp = arr_chess[cur_number];

        cur_number = (cur_number+1) % K;

        printf("%d %d %d %d\n",temp.y, temp.x, temp.number, temp.direction[1]);

        int new_y = temp.y + temp.direction[0];
        int new_x = temp.x + temp.direction[1];

        vector< Chess > group;

        bool check = false;


        
        for(int i=0; i<map_info[temp.y][temp.x].size(); i++){
           // printf("%d \n",map_info[temp.y][temp.x][i].number);

            if(!check){
                if(map_info[temp.y][temp.x][i].number == temp.number){
                    check = true;
                    group.push_back(map_info[temp.y][temp.x][i]);
                    map_info[temp.y][temp.x].erase(map_info[temp.y][temp.x].begin()+i);
                    i--;
                }
            }

            else{
                group.push_back(map_info[temp.y][temp.x][i]);
                map_info[temp.y][temp.x].erase(map_info[temp.y][temp.x].begin()+i);
                i--;
            }
            
        }
        


        if(0<= new_y && new_y <N &&
           0<= new_x && new_x <N && map[new_y][new_x] != BLUE){
               
               if(map[new_y][new_x] == WHITE){
                   for(int i=0; i<group.size(); i++){
                       group[i].y = new_y;
                       group[i].x = new_x;
                       arr_chess[group[i].number].y = new_y;
                       arr_chess[group[i].number].x = new_x;
                       map_info[new_y][new_x].push_back(group[i]);
                   }
               }

                else if(map[new_y][new_x] == RED){
                   for(int i=group.size()-1; i>=0; i--){
                       group[i].y = new_y;
                       group[i].x = new_x;
                       arr_chess[group[i].number].y = new_y;
                       arr_chess[group[i].number].x = new_x;
                       map_info[new_y][new_x].push_back(group[i]);
                   }
               }          

        }
        

        else{
            for(int i=0; i<group.size(); i++){

                group[i].direction[0] *= -1;
                group[i].direction[1] *= -1;
                arr_chess[group[i].number].direction[0] *= -1;
                arr_chess[group[i].number].direction[1] *= -1;

                int new_direction[2] = {group[i].direction[0], group[i].direction[1]};

                int new_y = temp.y + new_direction[0];
                int new_x = temp.x + new_direction[1];

                if(0<= new_y && new_y <N &&
                   0<= new_x && new_x <N &&
                   map[new_y][new_x] != BLUE){
                       group[i].y = new_y;
                       group[i].x = new_x;
                       arr_chess[group[i].number].y = new_y;
                       arr_chess[group[i].number].x = new_x;
                   }

                map_info[temp.y][temp.x].push_back(group[i]);
            }
        }

        Test();

        if(queue_count == K){
            queue_count = 0;
            printf("%d\n",count);

            Test();

            if(CheckMap()){
                printf("%d",count);
                return 0;
            }

            else if(count >= 1000){
                printf("-1");
                return 0;
            }

            else{
                count++;
            }


        }

    }
}