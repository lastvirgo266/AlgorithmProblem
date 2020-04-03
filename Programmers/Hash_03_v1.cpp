#include <string>
#include <vector>
#include <iostream>
#include <map>


using namespace std;


multimap<string, string> mm_clothes;
map<string, int> m_check;
int answer = 1;

void DFS(map<string,int>::iterator it_start, int result, int count){
    
    if(it_start == m_check.end()){
        answer += result;
        return ;
    }
    
    if(count >5){
        return ;
    }
    
    
    
    for(map<string,int>::iterator it = it_start; it != m_check.end(); it++){
        if(result == 0)
            result = 1;
        
        DFS((it), result*(mm_clothes.count((*it).first)), count+1);
    }
    
    DFS((it_start), result, count+1);
    
    
}

int solution(vector<vector<string>> clothes) {


    
    for(int i=0; i<clothes.size(); i++){
        mm_clothes.insert({clothes[i][1], clothes[i][0]});
        m_check.insert({clothes[i][1], 0 });
    }
    
    DFS(m_check.begin(),0,0);
    
    return answer;
}