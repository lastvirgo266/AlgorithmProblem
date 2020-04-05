#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v_ball;
int strike_list[3]={0,};
int answer = 0;

int Check(){
    for(int i=0; i<3; i++){
        bool result = false;
        for(int j=0; j<v_ball.size(); j++){
            if(strike_list[i] == v_ball[j])
                result = true;
        }
        
        if(!result){
            return 0;
        }
        
    }
    
    answer++;
    
    return 1;
}


void Permutation(vector<vector<int>> baseball,int index){
    
    if(strike_list[0] != 0 && strike_list[1] != 0 && strike_list[2] != 0 || v_ball.size() == 3){
        Check();
        return ;
    }
    
    string numbers = to_string(baseball[index][0]);
    vector<int> strike_permu;
    vector<int> ball_permu;
        
    //Init Presume Strike
    for(int i=0; i<baseball[index][1]; i++){
        strike_permu.push_back(1);
    }

    for(int i=0; i<3-baseball[index][1]; i++){
        strike_permu.push_back(0);
    }


    //Init Persmume Ball
    for(int i=0; i<baseball[index][2]; i++){
        ball_permu.push_back(1);
    }

    for(int i=0; i<3-baseball[index][2]; i++){
        ball_permu.push_back(0);
    }
        
    do{
        int temp_strike_list[3];
        
        for(int i=0; i<3; i++)
            temp_strike_list[i] = strike_list[i];
        
        for(int i = 0; i < 3; i++){
            if(strike_permu[i] == 1 && strike_list[i] == 0){
                strike_list[i] = numbers[i]-'0';
            }
        }
        
        do{
            for(int i=0; i<3; i++){
                if(ball_permu[i] == 1 && strike_list[i] == 0){
                    v_ball.push_back(numbers[i]-'0');
                }
            }
            
        }while(next_permutation(ball_permu.begin(), ball_permu.end()));
        
       Permutation(baseball, index+1);
        
        
        for(int i=0; i<3; i++)
            strike_list[i] = temp_strike_list[i];
        
        
    }while(next_permutation(strike_permu.begin(), strike_permu.end()));

    
}




int solution(vector<vector<int>> baseball) {
    
    Permutation(baseball, 0);

    return answer;
}