#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

map< pair<int, int >, int> cache;

bool solve(int start_x, int end_x, int start_y, int end_y){
    
    int min_x = min(start_x, end_x);
    int max_x = max(start_x, end_x);
    
    int min_y = min(start_y, end_y);
    int max_y = max(start_y, end_y);
    
    
    
    for(int i= min_y+1; i<max_y; i++){
        for(int j= min_x+1; j< max_x; j++){
            
            
            if((cache.find(make_pair(i,j)))->second == 1)
                return false;
        }
    }
    
    return true;
    
}


int solution(int n, vector<vector<int>> data) {
    int answer = 0;

    for(int i=0; i<data.size(); i++){
        cache[make_pair(data[i][0], data[i][1])] = 1;
    }
    
    
    
    for(int i=0; i<data.size(); i++){
        int start_y = data[i][0];
        int start_x = data[i][1];
        
        for(int j=i+1; j<data.size(); j++){
            int end_y = data[j][0];
            int end_x = data[j][1];
           
            if(abs(start_y-end_y) != 0 && abs(start_x - end_x) !=0 ){
            
            bool result = solve(start_x, end_x, start_y, end_y);
            
                if(result)
                    answer++;
                
            }
            
        }
    }
    
    return answer;
}