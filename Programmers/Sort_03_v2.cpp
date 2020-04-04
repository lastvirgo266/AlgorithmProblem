#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//또다른 버전


bool cmp (int a, int b){
    return a > b;
}


int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), cmp);
    
    int N = citations.size();
    answer = N;
    
    for(int i=0; i< citations.size();  i++){
        if(i >= citations[i]){
            answer = i;
            break;
        }
    }
    
    
    return answer;
}