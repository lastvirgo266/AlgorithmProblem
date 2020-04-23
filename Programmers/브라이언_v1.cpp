#include <string>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";
    
    char start_c = '1';
    char prev_c = '0';
    int start_number = 0;
    
    if('a' <= sentence[0] && sentence[0] <= 'z'){
        start_c = sentence[0];
    }
    
    
    for(int i = 0; i<sentence.size(); i++){
        
        if(start_c != '1' && start_c == sentence[i]){
            if(start_number < i && i < sentence.size()-1){
                start_c = sentence[i+1];
                start_number = i+1;
                prev_c = '0';
                answer += ' ';
            }
            
            else{
                continue;
            }
        }
        
        if('a' <=  sentence[i] && sentence[i] <= 'z'){
            
            
            char cur_c = sentence[i];
            
            if(prev_c != '0' && cur_c != prev_c){
                answer += ' ';
            }
            
            prev_c = cur_c;
            
        }
        
        else{
            answer += sentence[i];
        }
        
    }
    
    
    
    
    return answer;
}