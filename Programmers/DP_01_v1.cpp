#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int N;
unordered_set <int> cache[10];

unordered_set<int> solve(int count){
    
    if(!cache[count].empty()) return cache[count];
    
    int num = 0;
    
    for(int i=1; i <= count; i++) num = num*10 + N;
    
    
    
    unordered_set<int> res;
    res.insert(num);
    
    for(int i= 1; i<count; i++){
        int j = count - i;
        
        auto s1 = solve(i);
        auto s2 = solve(j);
    
        
        for(int n1 : s1){
            for(int n2 : s2){
                res.insert(n1 + n2);
                res.insert(n1 - n2);
                res.insert(n1 * n2);
                if(n2 != 0) res.insert(n1/n2);
            }
        }
        
    }
    
    return cache[count] = res;
    
    
}

int solution(int _N, int number) {
    int answer = 0;
    N = _N;
    
    for(int i=1; i<=8; i++){
        solve(i);
        if(cache[i].find(number) != cache[i].end() ) return i;
    }
    
    
    return -1;
}