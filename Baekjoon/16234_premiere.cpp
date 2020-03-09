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
int direct[4][2] = {{-1,0}, {0,1}, {1,0}, {0, -1}};
int N,L,R;

int Test(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ",map[i][j]);
        }

        printf("\n");
    }

    printf("\n\n\n");
}

int Solve(){
    int visited[50][50][5] = {0, };
    int blood[50] = {0,};
    int blood_count[50] = {0,};

    int group_split = 0;

    vector < vector< pair< int, int > > > blood_country;
    blood_country.resize(2);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){

            for(int k=0; k<4; k++){
                if(i+direct[k][0] >=0 &&
                   i+direct[k][0] <N &&
                   j+direct[k][1] >=0 &&
                   j+direct[k][1] <N ){

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

                        //연합을 만들었는지 체크
                        if(visited[i][j][GROUP] == 0){
                            visited[i][j][GROUP] = ++group_split;
                            blood_country[group_split].push_back({i,j});
                            blood[group_split] += map[i][j];
                            blood_count[group_split]++;
                        }

                        //우리와 이미 연합을 맺었는지 체크
                        if(visited[near_y][near_x][GROUP] == 0){
                            int now_group = visited[i][j][GROUP];
                            visited[near_y][near_x][GROUP] = now_group;
                            blood_country[now_group].push_back({near_y,near_x});
                            blood[now_group] += map[near_y][near_x];
                            blood_count[now_group]++;
                        }


                        visited[near_y][near_x][near_line] = 1;
                        visited[i][j][my_line] = 1;

                    }
                }
            }
    }

    int check = 0;


    for(int i=0; i<blood_country.size(); i++){
        if(blood_count[i] != 0){
            check = 1;
            for(int j=0; j<blood_country[i].size(); j++){
                int y = blood_country[i][j].first;
                int x = blood_country[i][j].second;

                printf("%d %d \n",y,x);

                map[y][x] = blood[i] / blood_count[i];
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

    while( (reuslt = Solve()) != 0 )
        count++;


    printf("%d",count);



}