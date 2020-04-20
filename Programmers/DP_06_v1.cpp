#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    int cache[1000000] = {0, };
    
    cache[0] = money[0];
    cache[1] = money[1];
    
    for(int i=2; i<=money.size(); i++){
        
        if(cache[i-1] > cache[i-2] + money[i]){
            cache[i] = cache[i-1];
        }
        
        else{
            cache[i] = cache[i-2] + money[i];
        }
        
        
    }
    
    answer = cache[money.size()-1];
    
    
    
    
    return answer;
}