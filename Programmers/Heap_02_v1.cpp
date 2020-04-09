#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int start_begin = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    
    
    while(stock < k){
        
        for(int i= start_begin; i<dates.size() && stock >= dates[i]; i++){
            pq.push(supplies[i]);
            start_begin++;
        }
        
        int max_sup = pq.top();
        pq.pop();
        
        stock += max_sup;
        answer++;

    }
    
    return answer;
}