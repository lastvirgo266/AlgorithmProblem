#include <string>
#include <vector>
#include <algorithm>
#define COL 0
#define FLAT 1

#define DELETE 0
#define INSTALL 1

using namespace std;

int col_map[102][102][102] = { { {0,}, }, }; // (x)[from y][to y+1]
int flat_map[102][102][102] = { { {0,}, }, }; // (y)[from x][to x+1]

int Install(int MAX, vector<int> pos){
    
    int x = pos[0];
    int y = pos[1];
    int type = pos[2];
    
    if(type == COL && y+1 <= MAX){
        if(y == 0){
            if(col_map[x][y][y+1] == 0){
                col_map[x][y][y+1] = 1;
                return 1;
            }
        }
        
        else{
            if(col_map[x][y][y+1] == 0 && (col_map[x][y-1][y] == 1|| 
               flat_map[y][x-1][x] || flat_map[y][x][x+1])){
                col_map[x][y][y+1] = 1;
                return 1; 
            }
        }
        
    }
    
    else if(type == FLAT && x+1 <= MAX){
        if(y==0){
            if(flat_map[y][x][x+1] == 0){
                flat_map[y][x][x+1] = 1;
                return 1;
            }
        }
        
        else if (flat_map[y][x][x+1] == 0){
            if((col_map[x][y-1][y] == 1 && col_map[x][y][y+1] == 0)  || 
               (flat_map[y][x-1][x] == 1 && flat_map[y][x+1][x+2] == 1)){
                flat_map[y][x][x+1] = 1;
                return 1;
            }
            
            else if(col_map[x+1][y-1][y] == 1 && col_map[x+1][y][y+1] == 0){
                flat_map[y][x][x+1] = 1;
                return 1;
            }
        }
        
    }
    
    
    return 0;
    
}




int Delete(int MAX, vector<int> pos){
    
    int x = pos[0];
    int y = pos[1];
    int type = pos[2];
    
    
    if(type == COL){
        if(col_map[x][y+1][y+2] == 1)
            return 0;
        
        else if(flat_map[y+1][x][x+1] ==1 && flat_map[y+1][x-1][x] == 0){
            return 0;
        }
        
        else{
            col_map[x][y][y+1] = 0;
            return 1;
        }

    }
    
    else if (type == FLAT){
        if(flat_map[y][x+1][x+2] == 1 || flat_map[y][x-1][x] == 1)
            return 0;
        else{
            flat_map[y][x][x+1] = 0;
        }
    }
    
    
    
    return 0;
    
}

void Active(int max, vector<vector<int>> frame){
    
    for(int i=0; i<frame.size(); i++){
        
        if(frame[i][3] == INSTALL){
            Install(max, frame[i]);
        }
        
        else
            Delete(max, frame[i]);
    }
    
    
    
}

void Result(int MAX, vector<vector<int>> &answer){
    
    
    //Col
    for(int x=0; x<=MAX; x++){
        for(int y=0; y<=MAX; y++){
            if(col_map[x][y][y+1] == 1){
                answer.push_back({x,y,COL});
            }
        }
    }
    
    for(int y=0; y<MAX; y++){
        for(int x=0; x<MAX; x++){
            if(flat_map[y][x][x+1] == 1){
                answer.push_back({x,y,FLAT});
            }
        }
    }
    
    
    sort(answer.begin(),answer.end());
    
    return ;
    
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    Active(n, build_frame);
    Result(n, answer);
    
    
    
    return answer;
}