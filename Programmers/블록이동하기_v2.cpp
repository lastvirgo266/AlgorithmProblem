#include <string>
#include <vector>
#include <queue>

using namespace std;

int direction[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int map[101][101] = { {0,}, };
int N;

int CheckRange(int y, int x, int weight_y, int weight_x){
    if(1<= y+weight_y && y+weight_y <=N){
        if(1<= x+weight_x && x+weight_x <=N)
            return 1;
        return 0;
    }
    
    return 0;
}

pair<int, int> RotateOut(pair<int,int> center, pair<int, int> out, pair<int,int> target){
    int weight_y =  target.first - out.first;
    int weight_x =  target.second - out.second;
    
    if(out.first+weight_y != center.first){
        if(map[out.first+weight_y][out.second] == 0){
            return target;
        }
    }
    
    else{
        if(map[out.first][out.second+weight_x] == 0){
            return target;
        }
    }
    
    
    return {-1,-1};
    
}

int Solve(){
    int visited[101][101] = { {0,}, };
    int min = 99999;
    
    queue< pair<int,int> , int> q;
    
    q.push({ {1,1}, 0 });
    q.push({ {1,2}, 0 });
    
    visited[1][1] = 1;
    visited[1][2] = 1;
    
    while(!q.empty()){
        pair< pair<int,int> , int> temp = q.front();
        q.pop();
        
        pair<int,int> center = temp.first;
        int now_time = temp.second;
        
        if(center.first == N && center.second == N){
            min = min < now_time ? min : now_time;
            continue;
        }
        
        //Move
        for(int i=0; i<4; i++){
            int pair_y = center.first + direction[i][0];
            int pair_x = center.second + direction[i][1];
            
            if(visited[pair_y][pair_x] == 1){
                for(int j=0; j<4; j++){
                    if(CheckRange(pair_y, pair_x, direction[j][0], direction[j][1]) && 
                       CheckRange(center.first, center,second, direction[j][0], direction[j][1])){
                        if()
                    }
                }
            }
            
        }
        
        
        
    }
    
    
    
    
}



int solution(vector<vector<int>> board) {
    int answer = 0;
    return answer;
}