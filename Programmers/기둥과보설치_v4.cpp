#include <string>
#include <vector>
#include <algorithm>
#define COL 0
#define FLAT 1

#define DELETE 0
#define INSTALL 1

using namespace std;

int col_map[103][103][103] = { { {0,}, }, }; // (x)[from y][to y+1]
int flat_map[103][103][103] = { { {0,}, }, }; // (y)[from x][to x+1]

int Install(int MAX, vector<int> pos){
    
    int x = pos[0];
    int y = pos[1];
    int type = pos[2];
    
    if(type == COL){
        if(y == 0){
            col_map[x][y][y+1] = 1;
            return 1;
        }
        
        else{
            if(col_map[x][y-1][y] == 1){
                col_map[x][y][y+1] = 1;
                return 1;
            }
            
            else if( (x>=1 && flat_map[y][x-1][x] == 1) || flat_map[y][x][x+1] == 1){
                col_map[x][y][y+1] = 1;
                return 1;
            }
        }
        
        return 0;
        
    }
    
    else if(type == FLAT){
        if(y==0){
            return 0;
        }
        
        else{
            if(col_map[x][y-1][y] == 1 || col_map[x+1][y-1][y] == 1){
                flat_map[y][x][x+1] = 1;
                return 1;
            }
            
            else if(col_map[x][y-1][y] == 0 && 
                    (x>=1 && flat_map[y][x-1][x] == 1) && flat_map[y][x+1][x+2] == 1){
                flat_map[y][x][x+1] = 1;
                return 1;
            }
        }
        
    }
    
    
    return 0;
    
}




int Delete(int MAX, vector<int> pos){
    
    int ori_x = pos[0];
    int ori_y = pos[1];
    int ori_type = pos[2];
    
    if(ori_type == COL)
        col_map[ori_x][ori_y][ori_y+1] = 0;
    else
        flat_map[ori_y][ori_x][ori_x+1] = 0;
    
        
        for(int x = 0; x<=MAX+1; x++){
            for(int y = 0; y<=MAX+1; y++){
                
                if(col_map[x][y][y+1] == 1){
                    vector<int> temp;
                    temp.push_back(x);
                    temp.push_back(y);
                    temp.push_back(COL);
                    
                    col_map[x][y][y+1] = 0;
                    
                    int result = Install(MAX, temp);
                    
                    col_map[x][y][y+1] = 1;
                    
                    if(!result){
                        if(ori_type==COL)
                            col_map[ori_x][ori_y][ori_y+1] = 1;
                        else
                            flat_map[ori_y][ori_x][ori_x+1] = 1;
                        
                        return 0;
                    }
                    
                }
                
                
                if(flat_map[y][x][x+1] == 1){
                    vector<int> temp;
                    temp.push_back(x);
                    temp.push_back(y);
                    temp.push_back(FLAT);
                    
                    flat_map[y][x][x+1] = 0;
                    
                    int result = Install(MAX, temp);
                    
                    flat_map[y][x][x+1] = 1;
                    
                    if(!result){
                        if(ori_type==COL)
                            col_map[ori_x][ori_y][ori_y+1] = 1;
                        else
                            flat_map[ori_y][ori_x][ori_x+1] = 1;
                        
                        return 0;
                    }
                    
                }
                
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
    
    for(int y=0; y<=MAX; y++){
        for(int x=0; x<=MAX; x++){
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