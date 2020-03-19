#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

int N;
int shark_size=2;
int shark_needs = 0;
int fish[20][20] = {0,};
int visited[20][20] = {0, };
int direction[4][2] = { {0, -1}, {-1, 0}, {1,0}, {0,1} };


//초안 작성 34분 종료
//실패


// int check(){
//     for(int i=0; i<N; i++)
//         for(int j=0; j<N; j++)
//             if(fish[i][j] <= shark_size)
//                 return 1;
    
//     return 0;
// }



int DFS(int y, int x, int second){

    int min = 9999999;

    for(int i=0; i<4; i++){

        int move_y = y+direction[i][0];
        int move_x = x+direction[i][0];


        if(0<= move_y && move_y < N &&
           0<= move_x && move_x < N){
               if(fish[move_y][move_x] <= shark_size && 
                  visited[move_y][move_x] == 0){
                      int temp_shark_needs = shark_needs;
                      int temp_shark_size = shark_size;
                      int temp_fish = fish[move_y][move_x];

                      if(fish[move_y][move_x] == shark_size)
                        shark_needs++;

                      fish[move_y][move_x] = 0;

                      if(shark_needs == shark_size){
                         shark_size++;
                         shark_needs = 0;
                      }

                      visited[move_y][move_x] = 1;
                      int result = DFS(move_y, move_x, second+1);

                      min = min < result ? min : result;

                      printf("%d\n",result);

                      shark_size = temp_shark_size;
                      shark_needs = temp_shark_needs;
                      fish[move_y][move_x] = temp_fish;
                      visited[move_y][move_x] = 0;
                      
                      
                  }
        }


    }

    return second;

}


int main(){

    int y,x;



    scanf("%d",&N);


    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            scanf("%d",&fish[i][j]);

            if(fish[i][j] == 9){
                y = i;
                x = j;
            }
            
        }


    

    int result = DFS(y,x,0);


    printf("%d", result);



    return 0;

    



    
}