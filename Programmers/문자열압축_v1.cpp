#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int max_len = s.size();
    
    int min_len = max_len;
    
    for(int cur_len=1; cur_len<=max_len-1; cur_len++){
        
        string new_str = "";
        
        string temp_str = "";
        
        string comp_str = "";
        for(int i=0; i<cur_len; i++)  comp_str += s[i];
        
        
        for(int i=0; i<s.size(); i+=cur_len){
            
            if( (s.size()-1) <= (i+cur_len-1) ){
                
                if((s.size()-1) == (i+cur_len-1)){
                    if(comp_str == s.substr(i, cur_len)){
                        temp_str += s.substr(i, cur_len);
                        i += cur_len;
                    }
                }
                
                int temp_size = temp_str.size() / cur_len;
                
                if(temp_size == 1){
                    new_str += temp_str;
                }
                else{
                    new_str += to_string(temp_size)+temp_str.substr(0,cur_len);
                }
                
                new_str += s.substr(i, s.size()-i);
                break;
            }
            
            if(comp_str == s.substr(i, cur_len)){
                temp_str += s.substr(i, cur_len);
            }
            
            else{
                comp_str = s.substr(i,cur_len);
                
                int temp_size = temp_str.size() / cur_len;
                
                if(temp_size == 1){
                    new_str += temp_str;
                }
                else{
                    new_str += to_string(temp_size)+temp_str.substr(0,cur_len);;
                }
                
                temp_str = "";
                temp_str += s.substr(i,cur_len);
                
            }
            
            
        }
        
        //cout<<new_str<<endl;
        min_len = min_len < new_str.size() ? min_len : new_str.size();
        
        
        
    }
    
    answer = min_len;
    
    return answer;
}