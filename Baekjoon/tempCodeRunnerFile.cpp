#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define GROUP 4


int map[50][50] = {0,};
int direct[4][2] = {{-1,0}};
int N,L,R;


int Solve(){
    int visited[50][50][5] = {0, };
    int blood = 0;
    int blood_count = 0;

    vector< pair< int, int > > blood_country;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){

            for(int k=0; k<4; k++){
                if(i+direct[k][0] >=0 &&
                   i+direct[k][0] <N &&
                   j+direct[k][1] >=0 &&
                   j+direct[k][1] <N )
                {
                    int near_y = i+direct[k][0];
                    int near_x = j+direct[k][1];
                    int result = abs(map[near_y][near_x] - map[i][j]);
                    int my_line = k;
                    int near_line = (k+2)%4;

                    //근처에 있는 나라와 접촉한적이 있는지, 인구는 적절한지 체크
                    if(visited[near_y][near_x][near_line] == 0 &&
                    visited[i][j][my_line] == 0 &&
                    result <= R && 
                    result >= L){

                        //우리와 이미 연합을 맺었는지 체크
                        if(visited[near_y][near_x][GROUP] == 0){
                            blood_country.push_back({near_y,near_x});
                            blood += map[near_y][near_x];
                            blood_count++;
                            visited[near_y][near_x][GROUP] = 1;
                        }

                        //이미 연합을 맺었는지 체크
                        if(visited[i][j][GROUP] == 0){
                            blood_country.push_back({i,j});
                            blood += map[i][j];
                            blood_count++;
                            visited[i][j][GROUP] = 1;
                        }

                        visited[near_y][near_x][near_line] = 1;
                        visited[i][j][my_line] = 1;

                    }
                }
            }
    }

    if(blood_count == 0){
        return 0;
    }

    for(int i=0; i<blood_country.size(); i++){
        int y = blood_country[i].first;
        int x = blood_country[i].second;

        map[y][x] = blood / blood_count;
    }

    return 1;

}

int main(){

    scanf("%d %d %d", &N, &L, &R);

    int count = 0;
    int reuslt = 0;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d",&(map[i][j]));

    while( (reuslt = Solve()) != 0 )
        count++;


    printf("%d",count);



}