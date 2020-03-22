#include<stdio.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int shark_size=2;
int shark_needs = 0;
int fish[20][20] = {0,};

int move_direction[4][2] = { {-1, 0}, {0, -1}, {1,0}, {0,1} };
int eat_direction[4][2] = { {0,-1}, {-1 ,0}, {0,1}, {1,0} };

//V2작성 30분 소모

bool cmp( pair < pair<int, int>, int>  a, pair< pair<int, int>, int> b){
    if(a.second <= b.second){
        if(a.second == b.second){
            if(a.first.first <= b.first.first){
                if(a.first.first == b.first.first){
                    if(a.first.second < b.first.second){
                        return true;
                    }

                    return false;
                }

                return true;
            }

            return false;
        }

        return true;
    }

    return false;
    

}



int main(){

    int start_y, start_x;



    scanf("%d",&N);


    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            scanf("%d",&fish[i][j]);

            if(fish[i][j] == 9){
                fish[i][j] = 0;
                start_y = i;
                start_x = j;
            }
            
        }

    //초기화완료

    queue<pair <int, int> > shark_q;
    shark_q.push({start_y, start_x});
    int last_second = 0;
    shark_needs = shark_size;

    //샤크 큐 시작
    while(!shark_q.empty()){

        int visited[20][20] = {0, };

        pair< int, int > temp = shark_q.front();
        shark_q.pop();

        int shark_y = temp.first;
        int shark_x = temp.second;
        visited[shark_y][shark_x] = 1;
        vector < pair< pair<int, int> , int > > fish_list;

        //{ {y,x}, second }
        queue< pair< pair<int, int> , int> > fish_q;

        fish_q.push( {{shark_y, shark_x}, last_second});

        //현재 샤크위치를 기준으로 브루트포스로 다 탐색하고 그중에 최선 하나를 골라서 물고기 냠냠
        while(!fish_q.empty()){
            pair<int, int> temp_pos = fish_q.front().first;
            int temp_second = fish_q.front().second;
            fish_q.pop();

            //move shark
            for(int i=0; i<4; i++){
                int go_y = temp_pos.first + move_direction[i][0];
                int go_x = temp_pos.second + move_direction[i][1];

                if(0<= go_y && go_y <N &&
                   0<= go_x && go_x < N &&
                   visited[go_y][go_x] == 0 &&
                   fish[go_y][go_x] <= shark_size){
                       visited[go_y][go_x] = 1;
                       pair < pair < int, int > , int > temp; 
                       fish_q.push({ {go_y, go_x}, temp_second+1});

                       if(0 < fish[go_y][go_x] && fish[go_y][go_x] < shark_size)
                            fish_list.push_back( {{go_y, go_x}, temp_second+1});

                    }

            }

        }//End While


        //여기서 샤크가 생각한 물고기를 정렬하고 먹는 부분
        if(fish_list.size() == 0)
            continue;

        else{
            sort(fish_list.begin(),fish_list.end(), cmp);
            last_second = fish_list[0].second;
            fish[fish_list[0].first.first][fish_list[0].first.second] = 0;
            shark_needs--;
            if(shark_needs == 0){
                shark_size++;
                shark_needs = shark_size;
            }

            shark_q.push({fish_list[0].first.first, fish_list[0].first.second});
        }



    }


    printf("%d",last_second);


    return 0;
    
}