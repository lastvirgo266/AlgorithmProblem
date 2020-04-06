#include <string>
#include <vector>
#include <stack>

using namespace std;

int networks[201][201] = { {0, }, };
int result[201] = {0,};


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(computers[i][j] == 1)
                networks[i+1][j+1] = 1;
        }
    }
    
    stack< pair<int, int> > s;
    
    for(int i=1; i<=n; i++){
        bool check = false;
        
        for(int j= 1; j<=n; j++){
            if(networks[i][j] == 1){
                s.push({i,j});
                check = true;
            }
        }
        
        while(!s.empty()){
            pair<int, int> temp = s.top();
            s.pop();
            
            networks[temp.first][temp.second] = 2;
            
            for(int i=1; i<=n; i++){
                if(networks[temp.second][i] == 1){
                    s.push({temp.second, i});
                }
            }
            
        }
        
        if(check)
            answer++;
        
        
        
    }
    
    
    
    
    return answer;
}