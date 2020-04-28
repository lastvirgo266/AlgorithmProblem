#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    answer.resize(queries.size());
    
    for(int i=0; i<queries.size(); i++){
        
        int prefix = 0;
        int postfix = 0;
        
        
        int matching = 0;
        for(int j=0; j<words.size(); j++){
            
            int origin_start = 0;
            
            if(words[j].size() != queries[i].size())
                continue;
            
            if(queries[i][0] == '?'){
                if(queries[i][queries[i].size()-1] == '?')
                    origin_start = queries[i].size()-1;
                
                else
                for(int count =0; queries[i].size(); count++){
                    if(queries[i][count] == '?') continue;
                    else{
                        origin_start = count;
                        break;
                    }
                }
                
            }
            
            
            bool check = true;
            for(int k=0; k<words[j].size(); k++){
                
                if(origin_start != 0 && k == 0){
                    k = origin_start;
                }
                
                //Only Postfix
                if(queries[i][k] == '?' && k != 0 && queries[i][0] != '?')
                    break;
                
                if(queries[i][k] == '?')
                    continue;
                
                if(queries[i][k] != words[j][k]){
                    check = false;
                    break;
                }
                
                
            }
            
            if(check){
                matching++;
            }
            
            
            
        }
        
        answer[i] = matching;
        
        
    }
    
    return answer;
}