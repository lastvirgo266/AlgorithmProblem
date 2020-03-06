#include<stdio.h>
#include<queue>
#include<math.h>
#define CLOSED 3

using namespace std;

short weight[4][2] = {
    {0,1}, {1,0}, {0, -1}, {-1,0}
};
short map[50][50]= {0,};
int N,M;

typedef struct _point{
    short y,x;
}Point;

int CalculateDistance(){
    int score = 0;

    for(int i=0; i<N ; i++)
        for(int j=0; j<N; j++){
            if(map[i][j] == 1){


                short visited[50][50] = {0,};
                Point start;
                start.y = i;
                start.x = j;

                queue<Point> q;

                q.push(start);

                while(!q.empty()){
                    Point temp = q.front();
                    q.pop();

                    visited[temp.y][temp.x] = 1;

                    if(map[temp.y][temp.x] == 2 ){
                        int result = 
                            abs(temp.y  - start.y) + abs(temp.x - start.x);
                        score += result;
                        break;
                    }

                    else{
                        for(int i=0; i<4; i++){
                            if(temp.y + weight[i][0] < N &&
                               temp.y + weight[i][0] >= 0 &&
                               temp.x + weight[i][1] < N &&
                               temp.x + weight[i][1] >= 0){
                                   if(visited[temp.y + weight[i][0]][temp.x + weight[i][1]] == 0){
                                        Point new_point;
                                        new_point.y = temp.y + weight[i][0];
                                        new_point.x = temp.x + weight[i][1];

                                        q.push(new_point);
                                   }
                               }
                        }
                    }


                }



            }


        }

    //Test
    //printf("%d\n", score);
    
    if(score == 0)
        return 999999999;

    return score;


}

// int DFSChicken(int NowM){

//     if(NowM == 0)
//         return CalculateDistance();
    

//     int min = 99999999;


//     for(int i=0; i<N; i++)
//         for(int j=0; j<N; j++){
            
//             if(map[i][j] == CLOSED){
//                 map[i][j] = 2;
//                 int result1;
                
//                 result1 = CalculateDistance();

//                 min = min < result1 ? min : result1;
                
//                 //Test
//                 //printf("%d %d %d\n",NowM, j, min);

//                 int result2 = DFSChicken(NowM-1);

//                 min = min < result2 ? min : result2;

//                 map[i][j] = CLOSED;
//             }

//         }




//         return min;




// }



int main(){


    scanf("%d %d",&N, &M);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == 2)
                map[i][j] = CLOSED;
        }
    

    //초기화 완료

    int min = CalculateDistance();
    int result = DFSChicken(M);

    min = min < result ? min : result;

    printf("%d",min);

    return 0;


}