#include <string>
#include <vector>
#include <queue>

using namespace std;

int direction[3][2] ={ {-1,0}, {0,1}, {-1,1} };
int max_y;
int max_x;
char board[31][31];

int CheckRange(pair<int,int> pos){
    if(0<=pos.first && pos.first <max_y){
        if(0<=pos.second && pos.second <max_x){
            return 1;
        }

        return 0;
    }
    return 0;
}

int Delete(){

    queue< pair<int,int> > q;
    int visited[101][101] = { {0,}, };
    vector< pair<int,int> > answer;

    for(int i=0; i<max_y; i++){
        for(int j=0; j<max_x; j++){
            if(board[i][j] != NULL){
                char target = board[i][j];
                vector< pair<int, int> > cache;
                cache.push_back({i,j});

                for(int k=0; k<3; k++){
                    if(CheckRange({i+direction[k][0], j+direction[k][1]}) && 
                       (target == board[i+direction[k][0]][j+direction[k][1]]) ){
                        cache.push_back({i+direction[k][0], j+direction[k][1]});
                    }
                }

                if(cache.size() == 4){
                    for(int i=0; i<4; i++){
                        if(visited[cache[i].first][cache[i].second] == 0){
                            visited[cache[i].first][cache[i].second] = 1;
                            answer.push_back({cache[i].first, cache[i].second});
                        }
                    }
                } 
            }
        }
    }

    int result = 0;
    for(int i=0; i<answer.size(); i++){
        board[answer[i].first][answer[i].second] = NULL;
        result++;
    }

    return result;

}


int Push(){
    int check = 0;
    for(int j=0; j<max_x; j++){
        vector< pair < pair<int,int>, char> > stack;
        for(int i=max_y; i>=0; i--){
            if(board[i][j] != NULL){
                stack.push_back({ {i,j}, board[i][j] });
                board[i][j] = NULL;
                check = 1;
            }
        }
        
        for(int i=0; i<stack.size(); i++){
            board[max_y-1-i][j] = stack[i].second;
        }
        
    }

    
    return check;
}


int solution(int m, int n, vector<string> _board) {
    int answer = 0;

    for(int i=0; i<_board.size(); i++){
        for(int j=0; j<_board[i].size(); j++){
            board[i][j] = _board[i][j];
        }
    }

    max_y = m;
    max_x = n;

    int result = 1;


    while(result){
        result = Delete();
        answer += result;

        Push();
    }

    return answer;
}