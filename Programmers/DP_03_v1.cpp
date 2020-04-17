#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

//시간초과 실패
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int max_height = triangle.size()-1;
    int max = 0;
    
    //value, (hight, cur)
    queue < pair< int, pair<int, int> > > q;
    
    q.push({triangle[0][0], {0,0} });
    
    int write = 0;
    
    while(!q.empty()){
        
        pair<int, pair<int,int> > temp = q.front();
        q.pop();
        
        if(temp.second.first == max_height){
            max = max > temp.first ? max : temp.first;
        }
        
        else{
            int val = temp.first;
            int now_hight = temp.second.first;
            int cur = temp.second.second;
            q.push({val + triangle[now_hight+1][cur], {now_hight+1, cur} });
            q.push({val + triangle[now_hight+1][cur+1], {now_hight+1, cur+1} });
        }
        
        
    }
    
    answer = max;
    
    return answer;
}