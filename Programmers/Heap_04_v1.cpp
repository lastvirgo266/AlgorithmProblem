#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue <int, vector<int>, greater<int> > min_q;
    priority_queue <int, vector<int>, less<int> > max_q;
    
    
    for(int i=0; i<operations.size(); i++){
        string temp = operations[i];
        
        if(temp[0] == 'I'){
            int number = stoi(temp.substr(2));
            max_q.push(number);
            min_q.push(number);
        }
        
        else if(temp.substr(0,3) == "D -"){
            if(min_q.size() == 1){
                priority_queue <int, vector<int>, greater<int> > swap_q;
                priority_queue <int, vector<int>, less<int> > swap_q_1;
                swap(min_q, swap_q);
                swap(max_q, swap_q_1);
            }
            
            else
                min_q.pop();
        }
        
        else if(temp.substr(0,1) == "D"){
            if(max_q.size() == 1){
                priority_queue <int, vector<int>, greater<int> > swap_q;
                priority_queue <int, vector<int>, less<int> > swap_q_1;
                swap(min_q, swap_q);
                swap(max_q, swap_q_1);
            }
            
            else
                max_q.pop();
        }
        
    }
    
    int max = 0;
    int min = 0;
    
    if(max_q. size() != 0){
        max = max_q.top();
        min = min_q.top();
    }
    

    
    answer.push_back(max);
    answer.push_back(min);
    

    
    
    return answer;
}