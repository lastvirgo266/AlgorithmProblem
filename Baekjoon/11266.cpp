#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;

vector< vector<int> > node;
int visit[10001]={0,};

int DFS(int start_vertex){

    visit[start_vertex] = 1;

    
    for(int i=0; i < node[start_vertex].size(); i++){
        if(visit[ (node[start_vertex][i]) ] != 1)
            DFS(i);
    }

    return start_vertex;

}


int main(){

    int V;
    int E;

    scanf("%d %d", &V, &E);

    node.resize(V+1);


    for(int i=0; i<E; i++){
        int temp_input_1;
        int temp_input_2;

        scanf("%d %d",&temp_input_1, &temp_input_2);

        node[temp_input_1].push_back(temp_input_2);
        node[temp_input_2].push_back(temp_input_1);
    }


    DFS(1);



    return 0;

}