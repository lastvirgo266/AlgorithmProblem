#include <string>
#include <vector>
#include <iostream>

using namespace std;


string solve(string temp){
    
    if(temp.size() <= 1)
        return temp;
    
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
            temp_u = temp.substr(0, i+1);
            temp_v = temp.substr(i+1);
            
            if(correct == true){
                temp = temp_u + solve(temp_v);
                return temp;
            }
            
            else{
                string new_str = "(" + solve(temp_v) + ")";
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
                return temp;
                
            }
        }
        
    }
    
    
}


string solution(string p) {
    string answer = "";
    int left = 0;
    int right = 0;
    
    answer = solve(p);
    //cout<<p<<endl;
    
    

    
    return answer;
}