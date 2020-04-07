#include <string>
#include <vector>

using namespace std;

int max_weight;
int max_length;
int visited[10001] = {0,};
int result = 9999999;

vector< pair<int, int> > car_state;


int MoveCar(int now_weight){

    if(car_state[0].second+1 > max_length){
        now_weight -= car_state[0].first;
        car_state.erase(car_state.begin()+0);
    }

    for(int i=0; car_state.size(); i++){
        car_state[i].second++;
    }
    
    return now_weight;


}


void DFS(int now_weight, int left_car, int sec, vector<int> &truck_weights){
    
    if(left_car == 0){
        result = result < sec ? result : sec;
        return;
    }
    
    now_weight = MoveCar(now_weight);
    sec++;
    
    //PutCar
    for(int i=0; i<truck_weights.size(); i++){
        if(visited[i] == 0 && truck_weights[i] + now_weight <= max_weight){
            visited[i] = 1;
            now_weight += truck_weights[i];
            car_state.push_back({truck_weights[i],1});
            
            DFS(now_weight, left_car-1, sec, truck_weights);
            
            car_state.pop_back();
            now_weight -= truck_weights[i];
            visited[i] = 0;
        }
    }
    
    
}


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    max_length= bridge_length;
    max_weight = weight;
    
    DFS(0, truck_weights.size(), 0, truck_weights);
    
    answer = result;
    
    return answer;
}