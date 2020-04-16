#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, long long> cache;

long long Solve(int n){
    if(cache[n] != 0) return cache[n];
    
    if(n == 1)
        return 1;
    else if(n == 2)
        return 1;
    long long width = Solve(n-1) + Solve(n-2);
    cache[n] = width;
    
    return width;
}


long long solution(int N) {
    long long answer = 0;
    
    if(N == 1) return 4;
    
    cache[1] = 1;
    cache[2] = 1;
    
    Solve(N);
    
    answer = cache[N]*4 + cache[N-1]*2;
    
    return answer;
}