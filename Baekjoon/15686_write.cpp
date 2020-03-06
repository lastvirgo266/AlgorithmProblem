#include<stdio.h>
#include<queue>
#include<vector>
#include<math.h>
#define CLOSED 3

using namespace std;

int survived[13] = {0,};
vector< pair<int, int> > home;
vector< pair<int, int> > chicken;
int N, M;

int result_min = 999999999;

int CalculateDistance(){
    int score = 0;

    for(int i=0; i<home.size(); i++){
        int min = 999999999;

        for(int j=0; j<chicken.size(); j++){
            if(survived[j] == 1){
                int result = abs(home[i].first - chicken[j].first) + 
                        abs(home[i].second - chicken[j].second);

                min = min < result ? min : result;
            }
        }

        if(min != 999999999)
            score += min;

    }

    return score;

}



void DFSChicken(int count, int nowM){

    if(nowM == M){
        int result =  CalculateDistance();
        result_min = result_min < result ? result_min : result;
    }

    if(count == chicken.size())
        return;
    
    survived[count] = 0;
    DFSChicken(count+1, nowM);

    survived[count] = 1;
    DFSChicken(count+1, nowM+1);

    survived[count] = 0;

}


int main(){


    int map[50][50] = {0,};


    scanf("%d %d",&N, &M);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == 1){
                home.push_back({i,j});
            }
            else if(map[i][j] ==2){
                chicken.push_back({i,j});
            }
                
        }
    

    //초기화 완료


    DFSChicken(0, 0);

    printf("%d", result_min);


    return 0;


}