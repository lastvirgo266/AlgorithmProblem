#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    queue< pair< string, int> > q;
    map<string, int> cache;
    
    for(int i=0; i<words.size(); i++){
        
        int count = 0;
        
        for(int j=0; j<words[i].size(); j++){
            if(begin[j] != words[i][j])
                count++;
        }
        
        if(count == 1)
            q.push({ words[i] , 1});
        
    }
    
    
    while(!q.empty()){
        
        pair< string, int > temp = q.front();
        q.pop();
        string temp_word = temp.first;
        int temp_count = temp.second;
        
        if(cache.find(temp_word)-> second == 1)
            continue;
        
        cache[temp_word] = 1;
        
        int count = 0;

        for(int j=0; j<target.size(); j++){
            if(temp_word[j] == target[j])
                count++;
        }

        if(count == target.size()){
            return temp_count;
        }
        
        
        for(int i=0; i<words.size(); i++){

            int count = 0;
            

            for(int j=0; j<words[i].size(); j++){
                if(temp_word[j] != words[i][j])
                    count++;
            }

            if(count == 1){
                q.push({ words[i] , temp_count+1});
            }

        }
        
        
        
        
    }
    
    
    
    
    return answer;
}