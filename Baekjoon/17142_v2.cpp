#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

//초안 40분
//테스트 30분
//디버깅 10분

int N,M;
int select[51] = {0,};
int map[51][51] = {0,};
int direction[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };
int temp_map[51][51] = {0,};
int result_min = 99999999;

vector< pair<int, int> > active_virus;
vector< pair<int, int> > virus_positon;

int Check(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(temp_map[i][j] == 0)
                return 0;

    return 1;

}

void MapParsing(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            if(map[i][j] == 1)
                temp_map[i][j] = -1;
            else if(map[i][j] == 2)
                temp_map[i][j] = -2;
            else
                temp_map[i][j] = 0;
        }
}


int BFS(){

    int visited[51][51] = {0,};
    int total_second = 999999999;

    queue< pair< pair<int, int>, int > > virus_q;

    for(int i=0; i<active_virus.size(); i++){
        visited[active_virus[i].first][active_virus[i].second] = 1;
        temp_map[active_virus[i].first][active_virus[i].second] = -3;
        virus_q.push({ {active_virus[i].first, active_virus[i].second}, 0 });
    }

    if(Check())
        return 0;


    while(!virus_q.empty()){
        pair< pair<int, int> , int > temp;
        temp = virus_q.front();
        virus_q.pop();

        int y = temp.first.first;
        int x = temp.first.second;
        int second = temp.second;


        for(int i=0; i<4; i++){
            int new_y = y + direction[i][0];
            int new_x = x + direction[i][1];

            if(0<= new_y && new_y < N && 0<= new_x && new_x < N &&
               visited[new_y][new_x] == 0 && temp_map[new_y][new_x] != -1){
                   if(temp_map[new_y][new_x] == 0){
                       visited[new_y][new_x] = 1;
                       total_second = second+1;
                       pair< pair<int, int>, int> temp;
                       temp_map[new_y][new_x] = second+1;
                       temp = { {new_y, new_x}, second+1 };
                       virus_q.push(temp);
                       //Test();
                   }

                   else if(temp_map[new_y][new_x] == -2){
                       visited[new_y][new_x] = 1;
                       pair< pair<int, int>, int> temp;
                       temp_map[new_y][new_x] = -4;
                       temp = { {new_y, new_x}, second+1};
                       virus_q.push(temp);
                   }

               }
        }



    }

    if(!Check())
        return total_second = 9999999;

    return total_second;


}

void DFS(int count, int num){
    if(count == M){
        MapParsing();
        int result = BFS();
        result_min = result_min < result ? result_min : result;
        return ;
    }

    for(int i=num; i<virus_positon.size(); i++){
        if(select[i] == 0){
            select[i] = 1;
            active_virus.push_back({virus_positon[i].first, virus_positon[i].second});
            DFS(count+1, i);
            active_virus.erase(active_virus.begin() + active_virus.size()-1);
            select[i] = 0;
        }
    }

}


int main(){
    scanf("%d %d",&N, &M);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] ==2)
                virus_positon.push_back({i,j});
        }

    DFS(0,0);

    if(result_min == 9999999)
        printf("-1");
    
    else
        printf("%d", result_min);


    return 0;
}