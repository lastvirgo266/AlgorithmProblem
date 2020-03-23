#include<stdio.h>
#include<vector>
using namespace std;


typedef struct __shark{
    //int y,x;
    int size;
    int speed;
    int direction[2];
}Shark;

int shark_map[101][101] = {0,};
int fish = 0;
vector< pair< pair<int, int> , Shark> > shark_list;
int Y,X;

//초안 작성 1시간걸림
//key, value ==>고유 값이 필요한데 pair를 써버림... (map을 써야했음)


void Test(){
    for(int i=0; i<Y; i++){
        for(int j=0; j<X; j++){
            printf("%d ",shark_map[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
}


void ParsingDirection(int direction, Shark &shark){
    if(direction == 1){
        shark.direction[0] = -1;
        shark.direction[1] = 0;
    }

    if(direction == 2){
        shark.direction[0] = 1;
        shark.direction[1] = 0;
    }

    if(direction == 3){
        shark.direction[0] = 0;
        shark.direction[1] = 1;
    }

    if(direction == 4){
        shark.direction[0] = 0;
        shark.direction[1] = -1;
    }

}

void EatShark(int row){
    bool cascade_end = false;

    for(int i=0; i<Y ; i++)
        if(shark_map[i][row] == 1){
            for(int k=0; k<shark_list.size(); k++){
                if(shark_list[k].first.first == i &&
                   shark_list[k].first.second == row){
                       fish += shark_list[k].second.size;
                       shark_list.erase(shark_list.begin()+k);
                       shark_map[i][row] = 0;
                       return;
                   }
            }
        }

}

void MoveAllShark(){

    vector< pair< pair<int, int>, Shark > > new_shark_list;
    int new_map[101][101] = {0,};

    int total_size = shark_list.size();

    for(int i=0; i<total_size; i++){
        int y = shark_list[i].first.first;
        int x = shark_list[i].first.second;
        Shark shark = shark_list[i].second;

        //printf("%d %d %d %d %d\n", y,x, shark.speed, shark.direction[0], shark.direction[1]);

        //MoveShark Y-axis
        if(shark.direction[0] != 0){
           int can_distance = shark.speed;
           while(can_distance != 0){
           
                if( 0 > y + can_distance*shark.direction[0]){
                    int reminder = y + can_distance*shark.direction[0];
                    can_distance = (-reminder);
                    shark.direction[0] = (-shark.direction[0]);
                    y = 0;
                }

                if(Y <= y + can_distance*shark.direction[0]){
                    int reminder = ( Y-1 ) - ( y + can_distance*shark.direction[0]);
                    can_distance = (-reminder);
                    shark.direction[0] = (-shark.direction[0]);
                    y = Y-1; 
                }

                else{
                    y = y + can_distance*shark.direction[0];
                    can_distance = 0;
                }

           }

        }//End if

        //Move shark X-axis
        if(shark.direction[1] != 0){
           int can_distance = shark.speed;
           while(can_distance != 0){
           
                if( 0 > x + can_distance*shark.direction[1]){
                    int reminder = x + can_distance*shark.direction[1];
                    can_distance = (-reminder);
                    shark.direction[1] = (-shark.direction[1]);
                    x = 0;
                }

                if(X <= x + can_distance*shark.direction[1]){
                    int reminder = (X - 1) - ( x + can_distance*shark.direction[1] );
                    can_distance = (-reminder);
                    shark.direction[1] = (-shark.direction[1]);
                    x = X-1; 
                }

                else{
                    x = x + can_distance*shark.direction[1];
                    can_distance = 0;
                }

           }



        }//End if


           if(new_map[y][x] != 0){
               for(int i=0; i<new_shark_list.size(); i++){
                   if(new_shark_list[i].first.first == y &&
                      new_shark_list[i].first.second == x &&
                      new_shark_list[i].second.size < shark.size){
                        new_shark_list[i].second = shark;
                      }
               }
            }

            else{
                new_shark_list.push_back({ {y,x}, shark } );
                new_map[y][x] = 1;
            }

            //printf("%d %d %d %d %d\n", y,x, shark.speed, shark.direction[0], shark.direction[1]);

    }


    //Reset

    shark_list.clear();

    for(int i=0; i<new_shark_list.size(); i++){
        shark_list.push_back(new_shark_list[i]);
    }

    //Rest
    for(int i=0; i<Y; i++)
        for(int j=0; j<X; j++)
            shark_map[i][j] = new_map[i][j];

    //Test();
    //printf("%d \n",shark_list.size());

}



int main(){

    int M;

    scanf("%d %d %d",&Y, &X, &M);

    for(int m = 0; m<M; m++){
        int r,c,s,d,z;
        scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);

        Shark new_shark;
        new_shark.size = z;
        new_shark.speed = s;
        ParsingDirection(d, new_shark);
        shark_list.push_back( { {r-1,c-1}, new_shark} );
        shark_map[r-1][c-1] = 1;
    }

    //Test();

    //초기화 종료

    for(int j=0; j<X; j++){
        EatShark(j);
        MoveAllShark();
    }


    printf("%d",fish);


    return 0;


}