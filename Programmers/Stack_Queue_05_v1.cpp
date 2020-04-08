#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


vector<int> solution(vector<int> prices) {
    vector<int> answer;
    queue<int> q;
    
    int max_second = prices.size();
    
    for(int i=1; i<=max_second; i++){
        q.push(i);
    }
    
    
    while(!q.empty()){
        
        int now_second = q.front();
        int index = now_second -1;
        int during =0;
        q.pop();
        
        int min = prices[index];
        
        for(int i=index; i<max_second; i++){

            if(min > prices[i]){
                during = i - index;
                break;
            }

            else{
                during = max_second - now_second;
            }
            
        }
        
        answer.push_back(during);
    
    }
    
    
    
    
    
    
    return answer;
}