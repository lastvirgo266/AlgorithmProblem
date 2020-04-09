#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    sort(scoville.begin(), scoville.end());
    
    while(scoville.size() != 0){
        
        bool check = false;
        
        if(scoville[0] < K){
            check = true;
        }
        
        if(check){
            
            if(scoville.size() <= 1)
                return -1;
            
            int first = scoville[0];
            scoville.erase(scoville.begin());
            int second = scoville[0];
            scoville.erase(scoville.begin());
            
            int result = first + (second *2);
            answer++;

            for(int i=0; i<scoville.size(); i++){
                if(result <= scoville[i]){
                    scoville.insert(scoville.begin()+i, result);
                    break;
                }
            }
            
            //Exception
            if(scoville.size() == 0)
                scoville.push_back(result);
            
        }
        
        else{
            return answer;
        }
    
    }
    
    
    return answer;
}