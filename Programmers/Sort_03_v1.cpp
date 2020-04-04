#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (int a, int b){
    return a > b;
}


int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), cmp);
    
    int N = citations.size();
    
    for(int i=0; i< citations.size();  i++){
        if(i+1 >= citations[i] &&  citations[i] >= citations.size() - citations[i] ){
            answer = citations[i];
            break;
        }
    }
    
    
    return answer;
}