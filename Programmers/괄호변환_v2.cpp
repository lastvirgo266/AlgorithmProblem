#include <string>
#include <vector>
#include <iostream>

using namespace std;


void solve(string &temp){
    
    if(temp.size() <= 1)
        return;
    
    bool correct = true;
    
    string temp_u = "";
    string temp_v = "";
    
    int left =0;
    int right =0;
    
    for(int i=0; i<temp.size(); i++){
        if(temp[i] == '('){
            left++;
        }
        
        else{
            right++;
        }
        
        if(left < right){
            correct = false;
        }
        
        if(left != 0 && left == right){
            temp_u = temp.substr(0, left+right);
            temp_v = temp.substr(left+right);
            
            if(correct == true){
                solve(temp_v);
            }
            
            else{
                string new_str = "(" + temp_v + ")";
                temp_v = new_str;
                
                temp_u = temp_u.substr(1, temp_u.size()-2);
                
                string new_u ="";
                for(int i=0; i<temp_u.size(); i++){
                    if(temp_u[i]==')'){
                        new_u += "(";
                    }
                    
                    else{
                        new_u += ")";
                    }
                        
                }
                
                temp_u = new_u; 
                
                temp = temp_v + temp_u;
                return;
                
            }
            
            temp = temp_u + temp_v;
            return;
        }
        
    }
    
    
}


string solution(string p) {
    string answer = "";
    int left = 0;
    int right = 0;
    
    solve(p);
    
    //cout<<p<<endl;
    
    answer = p;
    
    

    
    return answer;
}