#include<stdio.h>
#include<vector>
using namespace std;

int map[50][50]={0,};
int R,C,T;

int up_cleaner_y = 0;
int down_cleaner_y = 0;
int direct[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

inline int SpreadDust(int dust){ return dust/5;}

int Cal(){
    int result = 0;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j] != -1)
                result += map[i][j];
        }

    }

    return result;

}


void MoveDust(){
    int new_map[50][50] = {0,};
    new_map[up_cleaner_y][0] = -1;
    new_map[down_cleaner_y][0] = -1;

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++){

            if(map[i][j] >= 1){
                int divided_dust = SpreadDust(map[i][j]);
                new_map[i][j] += map[i][j];
                
                for(int k=0; k<4; k++){
                    int near_y = i + direct[k][0];
                    int near_x = j + direct[k][1];

                    if(near_y<R && 0<= near_y &&
                       near_x<C && 0<= near_x &&
                        map[near_y][near_x] != -1){
                        new_map[near_y][near_x] += divided_dust;
                        new_map[i][j] -= divided_dust;
                    }

                }

            }

        }

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            map[i][j] = new_map[i][j];

}



void ActiveUpCleaner(){
    vector<int> move_array;
    int inedx = 0;

    //Right
    int i = up_cleaner_y;
    int temp = 0;

    move_array.push_back(0);
    for(int j=1; j<C; j++){
        move_array.push_back(map[i][j]);
    }

    for(int j=1, index=0; j<C; j++, index++){
        map[i][j] = move_array[index];
    }
    temp = move_array[move_array.size()-1];
    move_array.resize(0);


    //Up
    int j = C-1;
    move_array.push_back(temp);
    for(int i= up_cleaner_y-1; i>=0; i--){
        move_array.push_back(map[i][j]);
    }

    for(int i=up_cleaner_y-1, index=0; i>=0; i--,index++){
        map[i][j] = move_array[index];
    }
    temp = move_array[move_array.size()-1];
    move_array.resize(0);



    //Left
    i = 0;
    move_array.push_back(temp);
    for(int j=C-2; j>=0; j--){
        move_array.push_back(map[i][j]);
    }

    for(int j=C-2, index=0; j>=0; j--, index++){
        map[i][j] = move_array[index];
    }
    temp = move_array[move_array.size()-1];
    move_array.resize(0);

    //Down
    j = 0;
    move_array.push_back(temp);
    for(int i=1; i<=up_cleaner_y-1; i++){
        move_array.push_back(map[i][j]);
    }
    
    for(int i=1, index=0; i<=up_cleaner_y-1; i++, index++){
        map[i][j] = move_array[index];
    }

    


}


void ActiveDownCleaner(){
    vector<int> move_array;
    int inedx = 0;

    //Right
    int i = down_cleaner_y;
    int temp = 0;

    move_array.push_back(0);
    for(int j=1; j<C; j++){
        move_array.push_back(map[i][j]);
    }

    for(int j=1, index=0; j<C; j++, index++){
        map[i][j] = move_array[index];
    }
    temp = move_array[move_array.size()-1];
    move_array.resize(0);



    //Down
    int j = C-1;
    move_array.push_back(temp);
    for(int i= down_cleaner_y+1; i<R; i++){
        move_array.push_back(map[i][j]);
    }

    for(int i= down_cleaner_y+1, index=0; i<R; i++, index++){
        map[i][j] = move_array[index];
    }
    temp = move_array[move_array.size()-1];
    move_array.resize(0);

    //Left
    i = R-1;
    move_array.push_back(temp);
    for(int j=C-2; j>=0; j--){
        move_array.push_back(map[i][j]);
    }

    for(int j=C-2, index=0; j>=0; j--, index++){
        map[i][j] = move_array[index];
    }
    temp = move_array[move_array.size()-1];
    move_array.resize(0);

    //Up
    j = 0;
    move_array.push_back(temp);
    for(int i=R-2; i>=down_cleaner_y+1; i--){
        move_array.push_back(map[i][j]);
    }

    for(int i=R-2, index=0; i>=down_cleaner_y+1; i--, index++){
        map[i][j] = move_array[index];
    }


}


int main(){
    scanf("%d %d %d", &R, &C, &T);

    int check = 1;

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == -1){
                if(check){
                    up_cleaner_y = i;
                    check = 0;
                }
                else
                    down_cleaner_y = i;
            }
        }


    while(T--){
        MoveDust();
        ActiveUpCleaner();
        ActiveDownCleaner();
    }


    printf("%d",Cal());

    return 0;

}