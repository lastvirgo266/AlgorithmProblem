#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct _pos{
    pair<int, int> center;
    pair<int, int> out;
    int status;
}Pos;

int map[101][101] = { {0, }, };
int weight[4][2] = { {1,0},{0,-1}, {1,0}, {-1,0} };
int N;


Pos VerRotate(Pos pos, int y_weight){
    
    int conti_y = pos.out.second;
    int conti_x = pos.out.second + y_weight;
    
    if(0<= conti_y && conti_y <= N && 
       0<= conti_x && conti_x <= N && map[conti_y][conti_x] == 0){
        
        int end_y = conti_y + y_weight;
        int end_x = conti_x;
        
        if(0<= end_y && end_y <= N && 
           0<= end_x && end_x <= N && map[end_y][end_x] == 0){
            pos.out.first = end_y;
            pos.out.second = end_x;
            
            return pos;
        }
        
    }
    
    pos.center.first = -1;
    return pos;
    
}


Pos HorRotate(Pos pos, int x_weight){
    
    int conti_y = pos.out.second; + x_weight;
    int conti_x = pos.out.second;
    
    if(0<= conti_y && conti_y <= N && 
       0<= conti_x && conti_x <= N && map[conti_y][conti_x] == 0){
        
        int end_y = conti_y;
        int end_x = conti_x + x_weight;
        
        if(0<= end_y && end_y <= N && 
           0<= end_x && end_x <= N && map[end_y][end_x] == 0){
            pos.out.first = end_y;
            pos.out.second = end_x;
            
            return pos;
        }
        
    }
    
    pos.center.first = -1;
    return pos;
    
}


int Solve(Pos pos){
    
    int visited[101][101] = { {0,}, };
    
    queue< pair<Pos,int> > q;
    int min_time = 99999;
    
    q.push({pos, 0});
    
    visited[pos.center.first][pos.center.second] = 1;
    visited[pos.out.first][pos.out.second] = 1;
    
    while(!q.empty()){
        pair<Pos, int> temp = q.first();
        q.pop();
        Pos pos = temp.first;
        
        if( (pos.center.fisrt == N && pos.center.second == N) ||
          (pos.out.fisrt == N && pos.out.second == N)){
            
        }
        
        //Ver
        if(pos.center.first == post.out.first){                
            
            for(int i= 0; i<2; ++){
                for(int j=1; j>= -1; j--){
                    if(j == 0)
                        continue;
                    
                    Pos temp_p = VerRotate(pos, j);

                    if(temp_p.center.first != -1 && 
                       visited[temp_p.out.first][temp_p.out.second] == 0){
                        visited[temp_p.out.first][temp_p.out.second] == 1;
                        q.push({temp_p, temp.second+1});
                    }
                }
                
                pair<int, int> change;
                change = pos.center;
                pos.center = pos.out;
                pos.out = change;
            }
            
        }
        
        
        if(pos.center.second == post.out.second){
            
            for(int i= 0; i<2; ++){
                for(int j=1; j>= -1; j--){
                    if(j == 0)
                        continue;
                    Pos temp_p = HorRotate(pos, j);

                    if(temp_p.center.first != -1 && 
                       visited[temp_p.out.first][temp_p.out.second] == 0){
                        visited[temp_p.out.first][temp_p.out.second] == 1;
                        q.push({temp_p, temp.second+1});
                    }
                }
                
                pair<int, int> change;
                change = pos.center;
                pos.center = pos.out;
                pos.out = change;
            }
            
            
        }
        
        
        
    }
    
    
}


int solution(vector<vector<int>> board) {
    int answer = 0;
    return answer;
}