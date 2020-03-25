#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;





//여기까지 20분걸림
int N;
int select[51][51] = { 0, };
int map[51][51] = {0,};
int direction[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };
int temp_map[51][51] = {0,};
int min = 99999999;

vector< pair<int, int> > active_virus;

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


void BFS(){

    int visited[51][51] = {0,};
    int total_second = 0;

    queue< pair< pair<int, int>, int > > virus_q;

    for(int i=0; i<active_virus.size(); i++){
        virus_q.push({ {active_virus[i].first, active_virus[i].second}, 0 });
    }


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

            if(0<= new_y && new_x < N && 0<= new_x && new_x < N &&
               visited[new_y][new_x] == 0 && temp_map[new_y][new_x] != -1){
                   if(temp_map[new_y][new_x] == 0){
                       visited[new_y][new_x] = 1;
                       total_second = second+1;
                   }

               }
        }



    }


}



void DFS(int count){
    if(count ==3){
        MapParsing();
        BFS();
        //대충 여기에 박으셈
    }


    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] == 2 &&
               select[i][j] == 0){
                   select[i][j] = 1;
                   active_virus.push_back({i,j});
                   DFS(count +1);
                   select[i][j] = 0;
            }
        }
    }


}


int main(){



    return 0;
}