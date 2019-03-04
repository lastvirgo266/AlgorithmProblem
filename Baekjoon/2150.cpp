#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<memory.h>
using namespace std;

    vector< vector<int> > adjacent_graph;
    vector< vector<int> > reverse_adjacent_graph;
    //stack <int> DFS;
    int visit_table[10001] = {0,};
    int matrix_N;
    int N;
    int ssc_count = 0;
    vector< vector<int> > ans;
    stack<int> temp;


void DFS(int now){
    visit_table[now] = 1;
    //cout<<now<<endl; //TEST
    for(int next : adjacent_graph[now])
        if(visit_table[next] != 1)
            DFS(next);

    temp.push(now);
}



void DFS_kosaraju(int now, vector<int> &ssc){
    visit_table[now] = 2;
    ssc.push_back(now);

   // cout<<"how Problem : "<<now<<endl;

    for(int next : reverse_adjacent_graph[now])
        if(visit_table[next] != 2)
            DFS_kosaraju(next, ssc);
}



int main(){
   // memset(visit_table, 0, sizeof(visit_table));


    cin>> matrix_N >> N; //공백으로 구분

    adjacent_graph.resize(matrix_N+1);
    reverse_adjacent_graph.resize(matrix_N+1);


    for(int i=1; i<=N; i++){
        int input_1, input_2;
        cin >> input_1 >> input_2;
        adjacent_graph[input_1].push_back(input_2);
        reverse_adjacent_graph[input_2].push_back(input_1);
    }


    // for(int i=1; i<=N; i++){
    //     if(adjacent_graph.size() != 0){
    //         DFS.push(i);
    //         break;
    //     }
    // }

    for(int i=1; i<=matrix_N; i++){
        if(visit_table[i] != 1) DFS(i);
    }


    // //Get DFS search result
    // while(!DFS.empty()){
    //     int top = DFS.top();
    //     DFS.pop();
    //     if(visit_table[top] != 1){
    //         visit_table[top] = 1;
    //         temp.push(top);
    //         for(int i=0; i<adjacent_graph[top].size(); i++){
    //             if(visit_table[adjacent_graph[top][i]] != 1 ){
    //                 DFS.push(adjacent_graph[top][i]);
    //             }
    //         }
    //     }
    // }

    // //Reverse Stack
    // while(!temp.empty()){
    //     DFS.push(temp.top());
    //     temp.pop();
    // }





    //Get SSC
    while(!temp.empty()){
        vector<int> ssc;
        stack<int> DFS_krsaj;
        int top = temp.top();
        temp.pop();

        if(visit_table[top] == 2) continue;

        DFS_kosaraju(top, ssc);

        sort(ssc.begin(),ssc.end());
        ssc.push_back(-1);
        ans.push_back(ssc);
        ssc_count++;

        //Kosaraju Algorithm
        // if(visit_table[top] != 2){
        //     DFS_krsaj.push(top);


        //     while(!DFS_krsaj.empty()){
        //         int ksraj_top = DFS_krsaj.top();
        //         DFS_krsaj.pop();
        //         if( visit_table[ksraj_top] != 2){
        //                 ssc.push_back(ksraj_top);
        //                 visit_table[ksraj_top] = 2;
                    
        //             for(int i=reverse_adjacent_graph[ksraj_top].size()-1; i>=0; i--){
        //                 if(visit_table[reverse_adjacent_graph[ksraj_top][i]] != 2 ){
        //                     DFS_krsaj.push(reverse_adjacent_graph[ksraj_top][i]);
        //                     //cout<<" now :"<<ksraj_top<<" next : "<<reverse_adjacent_graph[ksraj_top][i]; //TEST
        //                 }
        //             }
        //         }
        //     }

        //     sort(ssc.begin(),ssc.end());
        //     ssc.push_back(-1);
        //     ans.push_back(ssc);
        //     ssc_count++;
        // }



    }

    
    sort(ans.begin(), ans.end(), [](const vector<int> &i, const vector<int> &j) { return i[0] < j[0]; });
    cout<<ans.size()<<endl;


    for (auto &i : ans) {
		for (auto j : i){
           if(j == -1) cout<< j<<endl;
            else cout<< j<< ' ';
        }
	}




    return 0;
}