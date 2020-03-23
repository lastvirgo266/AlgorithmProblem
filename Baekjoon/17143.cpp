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
vector< pair< pair<int, int> , Shark> > shark_list;
int Y,X;

//초안 40분까지 걸림 다시시작
//key, value ==>고유 값이 필요한데 pair를 써버림... (map을 써야했음)


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

void EatShark();

void MoveAllShark(){

    vector< pair< pair<int, int>, Shark > > new_shark_list;
    int new_map[101][101] = {0,};

    int total_size = shark_list.size();

    for(int i=0; i<total_size; i++){
        int y = shark_list[i].first.first;
        int x = shark_list[i].first.second;
        Shark shark = shark_list[i].second;

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
                    int reminder = y - can_distance*shark.direction[0];
                    can_distance = (-reminder);
                    shark.direction[0] = (-shark.direction[0]);
                    y = Y-1; 
                }

                else{
                    y = y + can_distance*shark.direction[0];
                    can_distance = 0;
                }

           }

           new_map[y][x] = 1;

            if (new_shark_list.find("f") == m.end() ) {
            // not found
            } else {
            // found
            }

           new_shark_list.push_back({ {y,x}, shark } );


        }//End if

        //Move shark X-axis
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
                    int reminder = y - can_distance*shark.direction[0];
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

    }



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


    //초기화 종료


}