#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int check [101][101] = { {0,}, };
    
    int board[101][101] = { {0, }, };
    
    board[0][0] = 1;
    board[1][0] = 1;
    board[0][1] = 1;
    
    for(auto p : puddles){
        check[p[1]-1][p[0]-1] = -1;
    }
    
    for(int i=1; i<m; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == -1){
                board[i][j] =0;
            }
            
            if(i== 0 || j == 0){
                if(i== 0){
                    board[i][j] += board[i][j-1] % 1000000007;
                }
                
                else{
                    board[i][j] += board[i-1][j] % 1000000007;
                }
            }
            
            else{
                board[i][j] = (board[i-1][j] + board[i][j-1]) % 1000000007;
            }
            
            printf("%d\n",board[i][j]);
        }
    }
    
    answer = board[n-1][m-1];
    
    return answer;
}