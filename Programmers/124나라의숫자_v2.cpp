#include <string>
#include <vector>

using namespace std;



string ChangeToThree(int n){
    string answer  = "";
    
    while(n >= 3){
        int temp = 0;
        temp = ( n % 3);
        n /= 3;
        
        if(temp == 0){
            temp = 4;
            n--;
        }
        
        answer = to_string(temp) + answer;
        
    }
    
    if(n>=1){
        answer = to_string(n) + answer;
    }

    return answer;
    
    
    
}


string solution(int n) {
    string answer = "";
    
    answer = ChangeToThree(n);
    return answer;
}