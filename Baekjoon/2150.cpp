#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int main(){
    //int matrix_graph[101][101];
    vector< vector<int> > matrix_graph;
    int visit_tabe[10001] = {1,};
    int matrix_N;
    int N;
    vector<int> ans;
    int count = 2;

    cin>> matrix_N >> N; //공백으로 구분

    matrix_graph.resize(matrix_N+1);


    for(int i=1; i<=N; i++){
        int input_1, input_2;
        cin >> input_1 >> input_2;
        matrix_graph[input_1].push_back(input_2);
        //matrix_graph[input_1][input_2] = 1;
    }

    
    for(int i=1; i<=N; i++){
        stack< pair<int, int> > DFS;
        vector<int> SSC;
        int start = i;
        int prev = i;

        for(int j=1;j<=N; j++){
            if(matrix_graph[i][j] ==1){
                DFS.push(make_pair(i,j));
            }
        }

        SSC.push_back(i);
 
        //curretn = 2
        //used = 3
        //no = 0
        while(!DFS.empty()){
            pair<int, int> prev_now = DFS.top();
            SSC.push_back(DFS.top().second);
            DFS.pop();
            int prev = prev_now.first;
            int now = prev_now.second;

            if(matrix_graph[prev][now] == 1 && visit_tabe[prev] != 3){
                matrix_graph[prev][now] = 2;

                if(now == start){
                    SSC.push_back(-1);
                    ans.insert(ans.end(), SSC.begin(),SSC.end());
                    for(int i=0; i < SSC.size()-1; i++){
                        visit_tabe[SSC[i]] = 3;
                    }

                }

                for(int i=1; i<=N; i++){
                    if(matrix_graph[now][i] == 1){
                        DFS.push(make_pair(now,i));
                    }
                }
            }

        }
    }

    for(int i=0; i<ans.size();i++){
        cout<<ans[i];
        if(ans[i] == -1) cout <<endl;
    }


    return 0;
}