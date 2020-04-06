#include <string>
#include <vector>

using namespace std;
int answer = 0;
int g_target;

void DFS(vector<int> numbers, int index, int result){
    if(index == numbers.size()){
        if(result == g_target)
            answer++;
        return;
    }
    
    DFS(numbers, index+1, result+numbers[index]);
    DFS(numbers, index+1, result-numbers[index]);
    
    
}


int solution(vector<int> numbers, int target) {
    g_target = target;
    
    DFS(numbers, 0, 0);
    
    return answer;
}