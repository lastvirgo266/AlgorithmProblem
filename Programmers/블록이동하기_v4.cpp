#include <string>
#include <vector>
#include <queue>
using namespace std;

int visited[101][101][101][101] = { {0, },};
int direction[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int map[101][101] = { {0,}, };
int N;

int test_count = 0;

int Visited(pair<int,int> center, pair<int, int> out){
    pair<int,int> front;
    pair<int,int> back;
    
    if(center.first <= out.first){
        if(center.second <= out.second){
            front = center;
            back = out;
        }
        
        else{
            front = out;
            back = center;
        }
    }
    
    else{
        front = out;
        back  = center;
    }
    
    if(visited[front.first][front.second][back.first][back.second] == 0)
        return 1;
    
    else
        return 0;  
}

int SetVisited(pair<int,int> center, pair<int, int> out){
    pair<int,int> front;
    pair<int,int> back;
    
    if(center.first <= out.first){
        if(center.second <= out.second){
            front = center;
            back = out;
        }
        
        else{
            front = out;
            back = center;
        }
    }
    
    else{
        front = out;
        back  = center;
    }
    
    if(visited[front.first][front.second][back.first][back.second] == 0){
        visited[front.first][front.second][back.first][back.second] = 1;
        return 1;
    }
    
    else
        return 0;  
}

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
    int min = 99999;
    
    queue< pair <  pair < pair<int,int>,pair<int,int> > , int > > q;
    q.push({ { {1,1}, {1,2} }, 0 });
    
    SetVisited({1,1}, {1,2});
    
    
    while(!q.empty()){
        
        pair< int,int> center = q.front().first.first;
        pair< int, int> out = q.front().first.second;
        int now_time = q.front().second;
        q.pop();
        
        //printf("%d %d %d %d %d\n",center.first, center.second, out.first, out.second, now_time);
        
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
                if(Visited(new_center, new_out)){
                    SetVisited(new_center, new_out);
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
                continue;
            }
            
            new_out = RotateOut(center, out, new_out);
            
            if(new_out.first != -1){
                if(Visited(center, new_out)){
                    SetVisited(center, new_out);
                    q.push( { {center, new_out}, now_time+1 });
                }
            }
        }
        
        
        for(int i=0; i<4; i++){
            pair<int, int> new_center;
            new_center.first = out.first+direction[i][0];
            new_center.second = out.second+direction[i][1];
            
            if(new_center.first == center.first ||  new_center.second == center.second || 
               !CheckRange(new_center))
                continue;
            
            new_center = RotateOut(out, center, new_center);
            if(new_center.first != -1){
                if(Visited(out, new_center)){
                    SetVisited(out, new_center);
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
    
    N = board.size();
    
    answer = Solve();
    
    return answer;
}