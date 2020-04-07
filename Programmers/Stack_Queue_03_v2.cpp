#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    
    for(int i=0; i<progresses.size(); i++){
        
        int day = 0;
        
        if((100-progresses[i]) % speeds[i] != 0)
            day = (100 -progresses[i]) / speeds[i] + 1;
        else
            day = (100-progresses[i]) / speeds[i];
        
        days.push_back(day);
        
        
    }
    
    
    int max = days[0];
    int count = 0;
    
    for(int i=0; i<days.size(); i++){
        
        if(max >= days[i])
            count++;
        
        else{
            max = days[i];
            answer.push_back(count);
            count = 1;
        }
    }
    
    answer.push_back(count);

    return answer;
}