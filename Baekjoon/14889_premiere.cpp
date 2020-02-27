#include<stdio.h>
#include<stack>

#define START 1
#define LINK 2

using namespace std;

typedef struct _team_div{
    int now_start;
    int now_link;
    int now_index;
    int team_table[20];
}TeamDiv;

int main(){
    int N;
    int status_board[20][20]={{0,},};
    int min = 40001;


    scanf("%d",&N);

    for(int i=0; i<N; i++)
        for(int  j=0; j<N; j++)
            scanf("%d",&status_board[i][j]);


    //초기화 완료

    TeamDiv team_1;
    TeamDiv team_2;

    team_1.now_start = 1;
    team_1.now_link = 0;

    team_2.now_start = 0;
    team_2.now_link = 1;

    team_1.now_index=0;
    team_2.now_index=0;

    team_1.team_table[0] = START;
    team_2.team_table[0] = LINK;

    stack<TeamDiv> s;

    s.push(team_1);
    s.push(team_2);

    while(!s.empty()){
        TeamDiv temp = s.top();
        s.pop();

        if(temp.now_index == N-1){
            int start_point = 0;
            int link_point = 0;

            for(int i=0; i<N; i++)
                for(int j=i; j<N; j++)
                    if(temp.team_table[i] == START &&
                     temp.team_table[j] == START)
                        start_point += (status_board[i][j] + status_board[j][i]);
 

            for(int i=0; i<N; i++)
                for(int j=i; j<N; j++)
                    if(temp.team_table[i] == LINK &&
                     temp.team_table[j] == LINK)
                        link_point += (status_board[i][j] + status_board[j][i]);

            int result;
            result = link_point > start_point ? link_point - start_point : start_point - link_point;

            min = min < result ? min : result;

            continue;

        }

        if(temp.now_start < N/2){
            TeamDiv new_team;
            new_team.now_start = temp.now_start + 1;
            new_team.now_link = temp.now_link;
            new_team.now_index = temp.now_index;

            for(int i=0; i<N; i++)
                new_team.team_table[i] = temp.team_table[i];

            new_team.now_index++;
            new_team.team_table[new_team.now_index] = START;

            s.push(new_team);
        }

        if(temp.now_link < N/2){
            TeamDiv new_team;
            new_team.now_start = temp.now_start;
            new_team.now_link = temp.now_link + 1;
            new_team.now_index = temp.now_index;

            for(int i=0; i<N; i++)
                new_team.team_table[i] = temp.team_table[i];

            new_team.now_index++;
            new_team.team_table[new_team.now_index] = LINK;

            s.push(new_team);

        }



    }


    printf("%d",min);


    return 0;



}