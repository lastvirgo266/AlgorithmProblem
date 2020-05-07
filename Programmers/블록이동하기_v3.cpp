#include <string>
#include <vector>
#include <queue>
using namespace std;

int direction[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int map[101][101] = { {0,}, };
int N;

int test_count = 0;

int CheckRange(pair<int, int> pos ){
    if(1<= pos.first && pos.first <=N){
        if(1<= pos.second && pos.second <=N && map[pos.first][pos.second] == 0){
            return 1;
        }
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
    
    queue< pair <  pair < pair<int,int>,pair<int,int> > , int > > q;
    q.push({ { {1,1}, {1,2} }, 0 });
    
    visited[1][1] = 1;
    visited[1][2] = 1;
    
    
    while(!q.empty()){
        
        pair< int,int> center = q.front().first.first;
        pair< int, int> out = q.front().first.second;
        int now_time = q.front().second;
        q.pop();
        
        printf("%d %d %d %d %d\n",center.first, center.second, out.first, out.second, now_time);
        
        if(center.first == N && center.second == N){
            min = min < now_time ? min : now_time;
            continue;
        }
        
        if(out.first == N && out.second == N){
            min = min < now_time ? min : now_time;
            continue;
        }
        
        //Move
        for(int i=0; i<4; i++){
            pair<int, int> new_center = center;
            pair<int, int> new_out = out;
            
            new_center.first = center.first + direction[i][0];
            new_center.second = center.second + direction[i][1];
            
            new_out.first = out.first + direction[i][0];
            new_out.second = out.second + direction[i][1];
            
            if(CheckRange(new_center) && CheckRange(new_out)){
                if(visited[new_center.first][new_center.second] == 0 ||
                   visited[new_out.first][new_out.second] == 0){
                    visited[new_center.first][new_center.second] = 1;
                    visited[new_out.first][new_out.second] = 1;
                    
                    q.push({ {new_center,new_out}, now_time+1 });
                    
                }
            }
            
        }
        
        //Rotate
        for(int i=0; i<4; i++){
            pair<int, int> new_out;
            new_out.first = center.first+direction[i][0];
            new_out.second = center.second+direction[i][1];
            

            
            if(new_out.first == out.first || new_out.second == out.second || 
               !CheckRange(new_out)){
                printf("%d %d\n",new_out.first, new_out.second);
                continue;
            }
            
            new_out = RotateOut(center, out, new_out);
            
            if(new_out.first != -1){
                if(visited[new_out.first][new_out.second] == 0){
                    visited[new_out.first][new_out.second] = 1;
                    q.push( { {center, new_out}, now_time+1 });
                }
            }
        }
        
        
        for(int i=0; i<4; i++){
            pair<int, int> new_center;
            
            if(out.first+direction[i][0] == center.first || 
               out.second+direction[i][1] == center.second || 
               !CheckRange( {out.first+direction[i][0], out.second+direction[i][1]} ))
                continue;
            
            new_center = RotateOut(out, center, {out.first+direction[i][0],
                                               out.first+direction[i][1]});
            if(new_center.first != -1){
                if(visited[new_center.first][new_center.second] == 0){
                    visited[new_center.first][new_center.second] = 1;
                    q.push( { {out, new_center}, now_time+1 });
                }
            }
        }
        
        
        
    }
    
    
    return min;
    
}



int solution(vector<vector<int>> board) {
    int answer = 0;
    
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            map[i+1][j+1] = board[i][j];
        }
    }
    
    N = board.size()+1;
    
    answer = Solve();
    
    return answer;
}