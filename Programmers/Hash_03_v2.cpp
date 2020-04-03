#include <string>
#include <vector>
#include <iostream>
#include <map>


using namespace std;

int solution(vector<vector<string>> clothes) {

    int answer = 1;
    map<string,int> m_check;
    
    for(int i=0; i<clothes.size(); i++){
        
        if((m_check.find(clothes[i][1])->second) != 0){
            m_check[clothes[i][1]]++;
        }
        
        else{
            m_check.insert({clothes[i][1], 1 });
        }
    }
    
    for(map<string,int>::iterator it = m_check.begin(); it != m_check.end(); it++){
        answer *= ((*it).second+1);
    }
    
    answer--;
    
    return answer;
}