#include<stdio.h>
#include<vector>
using namespace std;



vector<int> v;
int visited[9] = {0,};
int N;

void DFS(int count){
    if(count == 0){
        //printf("\n");
        for(int i=0; i<N; i++)
            printf("%d ",v[i]);
        printf("\n");

        return;
    }
    
    for(int i=1; i<=N; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            v.push_back(i);
            DFS(count-1);
            visited[i] = 0;
            v.pop_back();
        }
    }

}




int main(){


    scanf("%d",&N);

    DFS(N);

    return 0;

}