#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sec = 0;
    
    int cur_weight=0;
    vector< pair<int, int> > bridge_list;
    
    bridge_list.push_back({truck_weights[0],0});
    cur_weight += truck_weights[0];
    truck_weights.erase(truck_weights.begin() + 0);
    
    
    while(1){
        
        sec++;
        
        for(int i=0; i<bridge_list.size(); i++){
            bridge_list[i].second++;
        }
        
        
        
        if(bridge_list[0].second > bridge_length){
            cur_weight -= bridge_list[0].first;
            bridge_list.erase(bridge_list.begin() + 0);
            
        }
        
        
        if(bridge_list.size() == 0 && truck_weights.size() == 0)
            return sec;
        
        if(cur_weight + truck_weights[0] <= weight && truck_weights.size() > 0){
            bridge_list.push_back({truck_weights[0],1});
            cur_weight += truck_weights[0]; 
            truck_weights.erase(truck_weights.begin() + 0);
         }
        
        
    }
    
}