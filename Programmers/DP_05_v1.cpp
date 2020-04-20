#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cache[2000][2000]= { {0, }, };
vector<int> left;
vector<int> right;

int solve(int left_index, int right_index){
    
    if(cache[left_index][right_index] != 0)
        return cache[left_index][right_index];
    
    if(left_index == left.size() || right_index == right.size())
        return 0;
    
    if(left[left_index] > right[right_index]){
        
        int cur = solve(left_index, right_index+1) + right[right_index];
        cache[left_index][right_index] = cur;
        return cur;
    }
    
    else{
        int cur = max(solve(left_index+1, right_index+1), solve(left_index+1, right_index));
        cache[left_index][right_index] = cur;
        return cur;
    }
    
    
    
}


int solution(vector<int> _left, vector<int> _right) {
    int answer = 0;
    left = _left;
    right = _right;
    
    answer = solve(0,0);
    
    return answer;
}