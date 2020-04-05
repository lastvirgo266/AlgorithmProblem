#include <string>
#include <vector>

using namespace std;
int solution(vector<vector<int>> baseball) {
    int answer = 0;
    
    
    for(int i = 123; i<=987; i++){
        
        string expect = to_string(i);
        
        if(expect[0] == expect[1] || expect[1] == expect[2] || expect[2] == expect[0])
            continue;
        if(expect[1] == '0' || expect[2]=='0')
            continue;
        
        bool result = true;
        
        
        for(int j=0; j<baseball.size(); j++){

            int expect_strike = 0;
            int expect_ball = 0;
            
            string temp = to_string(baseball[j][0]);
            
            for(int k=0; k<3; k++){
                if(expect[k] == temp[k])
                    expect_strike++;
            }
            
            for(int k=0; k<3; k++){
                if(expect[k] == temp[(k+1)%3] || expect[k] == temp[(k+2)%3])
                    expect_ball++;
            }
            
            if(expect_strike != baseball[j][1] || expect_ball != baseball[j][2]){
                result = false;
                break;
            }
            
        }
        
        if(result)
            answer++;
        
    }
    
    
    
    
    

    return answer;
}