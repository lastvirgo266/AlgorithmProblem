#include <string>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

bool cmp(string s1, string s2){
    return s1 > s2;
}

map<string, vector<string> > m;
int metro;



vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    map<string, int> cache; 

    
    
    for(int i=0;i< tickets.size(); i++){
        
        m[tickets[i][0]].push_back(tickets[i][1]);
        cache[tickets[i][0]] = 1;
        cache[tickets[i][1]] = 1;
    }
    
    
    
    for(map<string, vector<string> >::iterator it = m.begin(); it != m.end(); it++){
        
        sort((*it).second.begin(), (*it).second.end(), cmp);
        
    }
    
    metro = cache.size();
    
    printf("%d",metro);
    

    
    return answer;
}