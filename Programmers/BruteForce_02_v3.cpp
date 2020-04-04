#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <math.h>


using namespace std;
int visited[8] = {0,};
int answer = 0;
map<int,int> cache;

int Check(string result){
    if(result == "")
        return 0;
    
    
    map<int,int> eratos;
    
    int parsed_result = stoi(result);
    
    if(cache.find(parsed_result)-> second == 1 || parsed_result == 1 || parsed_result == 0){
        return 0;
    }
    
   // cout<<parsed_result<<endl;
    
    for(int i=2; i<=sqrt(parsed_result); i++){
        
        if(eratos.find(i)->second == 0){
            if(parsed_result % i == 0){
                cache[parsed_result] = 1;
                return 0;
            }
            else{
                for(int j=1; j*i<=sqrt(parsed_result) && 0 < j*i; j++)
                    eratos[i*j] = 1;
            }
        }
        
        
    }
    
    cache[parsed_result] = 1;
    answer++;
    
    
    return 1; 
}


void DFS(string numbers, string result, int stack){
    if(numbers.size() <= stack){
        Check(result);
        return ;
    }
    
    
    for(int i=0; i<numbers.size(); i++){
        if(visited[i] == 0){
            Check(result);
            visited[i] = 1;
            DFS(numbers, result+numbers[i], stack+1);
            visited[i] = 0;
        }
    }
    
    
}


int solution(string numbers) {
    string temp = "";
    
    DFS(numbers, temp, 0);
    return answer;
}