#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(),jobs.end());
    vector<int> completed_vector;
    priority_queue <pair<int,int>, vector< pair <int, int> >, greater<pair<int,int> > > pq;
    
    int total_second=0;
    int idx = 0;
    
    while(jobs.size() != idx || !pq.empty()){
        
        if(pq.empty() && total_second < jobs[idx][0]){
            total_second = jobs[idx][0];
            continue;
        }
        
        
        for(int i = idx; i<jobs.size() && total_second >= jobs[i][0]; i++, idx++){
            pq.push({jobs[i][1], jobs[i][0]});
        }
        
        
        
        pair<int, int> temp = pq.top();
        pq.pop();
        completed_vector.push_back(total_second - temp.second + temp.first);
        total_second += temp.first;
        
    }
    
    
    for(int i=0; i<completed_vector.size(); i++){
        answer += completed_vector[i];    
    }
    
    answer /= completed_vector.size();
    
    
    return answer;
}