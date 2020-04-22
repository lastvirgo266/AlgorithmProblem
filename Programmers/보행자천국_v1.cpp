#include <vector>
#define UP 0
#define LEFT 1
#define ALL 2
using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    
    int cache[501][501][3] = { { {0,}, }, };
    int map[501][501] = { {0, }, };
    
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++){
            map[i+1][j+1] = city_map[i][j];
        }
    
    cache[0][1][ALL] = 1;
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            
            if(map[i][j] == 1)
                cache[i][j][ALL] = 0;
            
            else{
                
                if(map[i][j-1] == 2)
                        cache[i][j][LEFT] = cache[i][j-1][LEFT];
                else
                    cache[i][j][LEFT] = cache[i][j-1][ALL];
                
                if(map[i-1][j] == 2)
                    cache[i][j][UP] = cache[i-1][j][UP];
                else
                    cache[i][j][UP] = cache[i-1][j][ALL];
            
                cache[i][j][ALL] = (cache[i][j][UP] + cache[i][j][LEFT])%MOD;
            }
            
            
        }
    }
    
    answer = cache[m][n][ALL];
    
    
    return answer;
}