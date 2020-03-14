#include<stdio.h>


int map[50][50]={0,};
int R,C,T;

int up_cleaner_y = 0;
int down_cleaner_y = 0;
int direct[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

inline int SpreadDust(int dust){ return dust/5;}

void MoveDust(){
    int new_map[50][50] = {0,};
    new_map[up_cleaner_y][0] = -1;
    new_map[down_cleaner_y][0] = -1;

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++){

            int divided_dust = SpreadDust(map[i][j]);
            
            for(int k=0; k<4; k++){
                int near_y = i + direct[k][0];
                int near_x = j + direct[k][1];

                if(map[near_y][near_x] == 0){
                    new_map[near_y][near_x] += divided_dust;
                    map[i][j] -= divided_dust;
                }

            }

        }

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            map[i][j] = new_map[i][j];

}



void ActiveUpCleaner(){

    //Right
    int i = up_cleaner_y;
    int temp = map[i][1];
    for(int j=1; j<C-1; j++){
        temp = map[i][j+1];
        map[i][j+1] = map[i][j];
    }


    //Up
    int j = C-1;
    int new_temp = 0;

    for(int i= up_cleaner_y-1; i>0; i--){
        new_temp = map[i-1][j];
        map[i-1][j] = map[i][j];
    }

    map[i-1][C-1] = temp;
    temp = new_temp;

    //Left
    i = 0;
    for(int j=C-1; j>0; j--){
        new_temp = map[i][j-1];
        map[i][j-1] = map[i][j];
    }

    map[0][C-1] = temp;
    temp = new_temp;

    //Down
    j = 0;
    for(int i=0; i<up_cleaner_y-1; i++){
        new_temp = map[i+1][j];
        map[i+1][j] = map[i][j];
    }

    map[0][0] = temp;

    


}


void ActiveDownCleaner(){

    //Right
    int i = down_cleaner_y;
    int temp = map[i][1];
    for(int j=1; j<C-1; j++){
        temp = map[i][j+1];
        map[i][j+1] = map[i][j];
    }


    //Down
    int j = C-1;
    int new_temp = 0;

    for(int i= up_cleaner_y+1; i<R-1; i++){
        new_temp = map[i+1][j];
        map[i+1][j] = map[i][j];
    }

    map[R-1][C-1] = temp;
    temp = new_temp;

    //Left
    i = R-1;
    for(int j=C-1; j>0; j--){
        new_temp = map[i][j-1];
        map[i][j-1] = map[i][j];
    }

    map[0][C-1] = temp;
    temp = new_temp;

    //Down
    j = 0;
    for(int i=0; i<up_cleaner_y-1; i++){
        new_temp = map[i+1][j];
        map[i+1][j] = map[i][j];
    }

    map[0][0] = temp;

}


int main(){

}