#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int visited[9] = {0,};
vector<int> small_people;
vector<int> true_list;



int DFS(int stack, int index){
    if(index > 9)
        return 0;

    else if(stack == 7){
        int result = 0;

        for(int i=0; i<7; i++)
            result += true_list[i];
        
        if(result == 100)
            return 1;
        else
            return 0;
    }

    int result;
    
    for(int i=index; i<9; i++){
        if(visited[i] == 0){
            true_list.push_back(small_people[i]);
            visited[i] = 1;
            result = DFS(stack+1, index+1);
            
            if(result == 1)
                return 1;
            visited[i] = 0;
            true_list.pop_back();
        }
    }

    result = DFS(stack, index+1);

    if(result == 1)
        return 1;
    
    return 0;
    
}




int main(){

    for(int i=0; i<9; i++){
        int temp;
        scanf("%d",&temp);
        small_people.push_back(temp);
    }


    DFS(0,0);


    sort(true_list.begin(), true_list.end());

    for(int i=0; i<7; i++)
        printf("%d\n",true_list[i]);


    return 0;



}

