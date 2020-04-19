#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int check [101][101] = { {0,}, };
    int board[101][101] = { {0, }, };
    
    board[1][0] = 1;
    
    for(auto p : puddles){
        check[p[1]][p[0]] = -1;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(check[i][j] == -1){
                board[i][j] = 0;
            }
            
            else{
                board[i][j] = (board[i-1][j] + board[i][j-1]) % 1000000007;
            }
        }
    }

    answer = board[n][m];
    
    return answer;
}