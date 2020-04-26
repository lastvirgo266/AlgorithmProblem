#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string p) {
    string answer = "";
    vector<int> left;
    vector<int> right;
    
    string temp = "";
    for(int i=0; i<p.size(); i++) temp += p[i];
    
    for(int i=0; i<temp.size(); i++){
        if(temp[i] == '(')
            left.push_back(i);
        
        else{
            if(left.size() > 0){
                int destroy = left[left.size()-1];
                left.pop_back();
                temp[destroy] = '1';
                temp[i] = '1';
            }
            
        }   
    }
    
    
    for(int i=0; i<p.size(); i++){
        if(temp[i] != '1'){
            if(p[i] == '(')
                p[i] = ')';
            else
                p[i] = '(';
        }

    }

    
    answer = p;
    
    return answer;
}