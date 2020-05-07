#include <string>
#include <vector>

using namespace std;



string ChangeToThree(int n){
    string answer  = "";
    
    while(n >= 3){
        int temp = 0;
        n--;
        temp = ( n % 3);
        
        if(temp == 0){
            if( n >= 3)
                n /= 3;
            temp = 3;
        }
        n /= 3;
        n++;
    }
    
    int temp = (n % 4);
        if(temp == 0 || temp == 1){
            answer += "1";
        }
        
        else if(temp == 2){
            answer += "2";
        }
        
        else {
            answer += "4";
        }
    
    return answer;
    
    
    
}


string solution(int n) {
    string answer = "";
    
    answer = ChangeToThree(n);
    return answer;
}