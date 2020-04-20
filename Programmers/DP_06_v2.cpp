#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    int cache_1[1000000] = {0, };
    int cache_2[1000000] = {0, };
    
    
    cache_1[0] = money[0];
    cache_1[1] = money[0];
    
    cache_2[1] = money[1];
    
    for(int i=2; i<money.size()-1; i++){
        cache_1[i] = max(cache_1[i-2]+money[i], cache_1[i-1]);
    }
    
    for(int i=2; i<money.size(); i++){
        cache_2[i] = max(cache_2[i-2]+money[i], cache_2[i-1]);
    }
    
    answer = max(cache_1[money.size()-2], cache_2[money.size()-1]);
    
    
    
    return answer;
}