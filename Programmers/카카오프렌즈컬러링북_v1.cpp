#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int direction[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0} };

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    int visited[100][100] = {0,};
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == 0 && picture[i][j] != 0){
                number_of_area++;
                int temp_area = 0;
                int target = picture[i][j];
                queue< pair<int,int> > q;
                q.push({i,j});
                
                while(!q.empty()){
                    pair<int, int> temp = q.front();
                    q.pop();
                    
                    int y = temp.first;
                    int x = temp.second;
                    
                    
                    if(visited[y][x] == 0 && picture[y][x] == target){
                        visited[y][x] = 1;
                        temp_area++;
                    }
                    
                    
                    for(int k=0; k<4; k++){
                        int new_y = y+direction[k][0];
                        int new_x = x+direction[k][1];
                        
                        if(0 <= new_y && new_y < m){
                            if(0 <= new_x && new_x < n)
                                if(picture[new_y][new_x] == target && visited[new_y][new_x] == 0){
                                    q.push({new_y, new_x});
                                }
                        }
                    }
                    
                }//end of while

                max_size_of_one_area = max(max_size_of_one_area, temp_area);
            }
        }// end of second for statement
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}