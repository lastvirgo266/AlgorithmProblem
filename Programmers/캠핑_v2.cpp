#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;


int solution(int n, vector<vector<int>> data) {
    int answer = 0;

    sort(data.begin(), data.end());
    
    for(int i=0; i<data.size(); i++){
        for(int j=i+1; j<data.size(); j++){
            
            int start_y = data[i][0];
            int start_x = data[i][1];
            int end_y = data[j][0];
            int end_x = data[j][1];
            
            int min_x = min(start_x, end_x);
            int max_x = max(start_x, end_x);
            
            int min_y = min(start_y, end_y);
            int max_y = max(start_y, end_y);
            
            if(min_x == max_x || min_y == max_y)
                continue;
            
            
            for(int k = i+1; k < j; k++){
                if(min_y < data[k][0] && data[k][0] < max_y &&
                   min_x < data[k][1] && data[k][1] < max_x){
                    answer--;
                    break;
                }
            }
            
            answer++;
            
        }
    }
    
    
    return answer;
}