#include<stdio.h>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;

int map[50][50] = {0,};

int direct[4][2] = {{-1,0}, {0,1}, {1,0}, {0, -1}};
int N,L,R;

int Solve(){
    int visited[50][50] = {0, };

    int check = 0;

    queue< pair <int, int> > blood_country;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            if(visited[i][j] == 0){
                queue< pair< int, int > > q;
                visited[i][j] = 1;
                blood_country.push({i,j});
                q.push({i,j});
                
                int sum = map[i][j];

                while(!q.empty()){

                    pair < int , int > temp;
                    temp = q.front();
                    q.pop();

                    int now_y = temp.first;
                    int now_x = temp.second;                

                    for(int k=0; k<4; k++){
                        if(now_y+direct[k][0] >=0 &&
                        now_y+direct[k][0] <N &&
                        now_x+direct[k][1] >=0 &&
                        now_x+direct[k][1] <N ){

                            int near_y = now_y+direct[k][0];
                            int near_x = now_x+direct[k][1];
                            int result = abs(map[near_y][near_x] - map[now_y][now_x]);

                            //근처에 있는 나라와 접촉한적이 있는지, 인구는 적절한지 체크
                            if(visited[near_y][near_x] == 0 &&
                            result <= R && 
                            result >= L){


                                visited[near_y][near_x] = 1;
                                q.push({near_y,near_x});


                                sum += map[near_y][near_x];
                                blood_country.push({near_y,near_x});


                            }


                            
                        }

                    }


                }//End of while

                int count = blood_country.size();
                if(count >=2 )
                    check = 1;

                while(!blood_country.empty()){
                    pair<int, int> temp = blood_country.front();
                    blood_country.pop();
                    map[temp.first][temp.second] = (sum / count);
                }


            }
        }

    if(check == 1)
        return 1;
    else
        return 0;

}

int main(){

    scanf("%d %d %d", &N, &L, &R);

    int count = 0;
    int reuslt = 0;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d",&(map[i][j]));

    while( (reuslt = Solve()) != 0 ){
        count++;
    }
    



    printf("%d",count);


    return 0;



}