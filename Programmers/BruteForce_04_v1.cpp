#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    
    int max = brown/2 +2;
    
    
    for(int i=max-3; i>= 3; i--){
        int j = max-i;
        if(i*j == brown + red){
            answer.push_back(i);
            answer.push_back(j);
            return answer;
        }
    }
    
    
    
    return answer;
}