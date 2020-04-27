#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<int, int> > lock_zip;
vector< pair<int, int> > key_zip;

int LOCK_SIZE = 0;
int KEY_SIZE = 0;

inline pair<int, int> Bangle(int y, int x){
    pair<int, int> temp;
    temp.first = x;
    temp.second = -y+(LOCK_SIZE-1);
    
    return temp;
}


int Check(vector< pair<int, int> > temp){
    
    pair<int, int> start = lock_zip[0];
    
    int start_y = start.first;
    int start_x = start.second;
    
    for(int i=0; i<key_zip.size(); i++){
    
        int y_weight = start_y - temp[i].first;
        int x_weight = start_x - temp[i].second;
        
        if(key_zip.size()-(i+1) < lock_zip.size())
            return 0;
        
        int answer_count = 0;

        for(int j = 0; j<lock_zip.size(); j++){
            for(int temp_count = 0; temp_count< key_zip.size(); temp_count++){
                if(temp[temp_count].first + y_weight == lock_zip[j].first &&
                   temp[temp_count].second + x_weight == lock_zip[j].second){
                    answer_count++;
                    break;
                }
            }
            
            if(answer_count== lock_zip.size())
                return 1;
        }
        
    }
    
    return 0;
}

//Clock Right (1/2*radian)
int Rotate(){
    
    vector< pair<int, int> > temp;
    
    
    
    for(int i=0; i<key_zip.size(); i++){
        pair<int, int> after_rotate = Bangle(key_zip[i].first, key_zip[i].second);
        temp.push_back({after_rotate.first,after_rotate.second});
        //printf("%d %d\n",after_rotate.first, after_rotate.second);
    }
    
    
    sort(temp.begin(), temp.end());
   

    
    if(Check(temp))
        return 1;
    
    key_zip = temp;
    
    return 0;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    LOCK_SIZE = lock.size();
    KEY_SIZE = key.size();    
    
    for(int i=0; i<LOCK_SIZE; i++){
        for(int j=0; j<LOCK_SIZE; j++){
            if(lock[i][j] == 0){
                lock_zip.push_back({i,j});
            }
        }
    }
    
    for(int i=0; i<KEY_SIZE; i++){
        for(int j=0; j<KEY_SIZE; j++){
            if(key[i][j] == 1){
                key_zip.push_back({i,j});
            }
        }
    }
    
    for(int i=0; i<4; i++){
        if(Rotate()){
            return true;
        }
    }
    
    
    return answer;
}