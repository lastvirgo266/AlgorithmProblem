#include <string>
#include <vector>
#define COL 0
#define FLAT 1

#define DELETE 0
#define INSTALL 1

using namespace std;

int col_map[101][101] = { {0,}, };
int flat_map[101][101] = { {0,}, };

int Install(int max, vector<int> pos){
    
    int x = pos[0];
    int y = pos[1];
    int type = -1;
    
    if(pos[2] == COL)
        type = COL;
    else
        type = FLAT;
    
    if(type == COL && y+1 < MAX){
        if(y == 0){
            if(col_map[x][y] == 0 && col_map[x][y+1] == 0){
                col_map[x][y] = 1;
                col_map[x][y+1] = 1;
                return 1;
            }
        }
        
        else{
            if((col_map[x][y] == 1 || flat_map[x][y] == 1) && col_map[x][y+1] == 0){
                col_map[x][y] = 1;
                col_map[x][y+1] = 1;
                return 1; 
            }
        }
        
    }
    
    else if(type == FLAT && x+1 < MAX){
        if(y==0){
            if(flat_map[x][y] == 0 && flat_map[x+1][y] == 0){
                flat_map[x][y] = 1;
                flat_map[x+1][y] = 1;
            }
        }
        
        else{
            if(flat_map[x][y] == 1){
            }
        }
        
    }
    
    
    
}




int Delete(int max, vector<int> pos);

void Active(int max, vector<vector<int>> frame){
    
    for(int i=0; i<frame.size(); i++){
        
        if(frame[i][3] == INSTALL){
            Install(max, frame[i])
        }
        
        else
            Delete(max, frame[i]);
    }
    
    
    
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    
    
    
    
    return answer;
}