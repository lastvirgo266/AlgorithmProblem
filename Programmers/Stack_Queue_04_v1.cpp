#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    vector< pair<int, int> > trav_v;
    
    for(int i=0; i<priorities.size(); i++){
        if(location == i){
            trav_v.push_back({priorities[i], 1});
        }
        
        else{
            trav_v.push_back({priorities[i], 0});
        }
    }
    
    int consume = 1;
    
    while(trav_v.size() != 0){
        
        //printf("%d \n",consume);
        
        int compare = trav_v[0].first;
        int max_index = 0;
        
        for(int i=0; i<trav_v.size(); i++){
            if(compare < trav_v[i].first){
                max_index = i;
                compare = trav_v[i].first;
            }
        }
        
        for(int i=0; i < max_index; i++){
            pair<int, int> temp = trav_v[0];
            trav_v.erase(trav_v.begin()+0);
            trav_v.push_back(temp);
        }


        if(trav_v[0].second == 1)
            return consume;        
        
        trav_v.erase(trav_v.begin()+0);       
        consume++;
        
    }
    

    
    return answer;
}