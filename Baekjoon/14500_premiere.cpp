#include<stdio.h>
using namespace std;


int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int board[500][500] = { {0, }, };
int visited[500][500] = { {0, }, };

int N;
int M;


int DFS(int y, int x, int depth){
    if(depth == 4){
        return board[y][x];
    }

    int sum = 0;
    for(int i=0; i<4; i++){
        if((y+dy[i]) >=0 && (x+dx[i]) >= 0 && //인덱스가 음수인지 검사
            (y+dy[i]) < N && (x+dx[i]) < M && //인덱스가 최대치를 넘어가는지 검사
            (visited[y+dy[i]][x+dx[i]] == 0)) //이미 조사한곳인지 검사
            {
                int result = 0;
                visited[y+dy[i]][x+dx[i]] = 1;
                result = DFS(y+dy[i], x+dx[i], depth+1) + board[y][x];
                visited[y+dy[i]][x+dx[i]] = 0;

                sum = sum > result ? sum : result;
            } 
    }

    return sum;
}




int Another(int y, int x){

    int result = 0;
    int max = 0;

    //ㅗ
    if (y >= 1 && x >= 1 && x < (M - 1)){
        result = board[y][x - 1] + board[y][x] + board[y - 1][x] + board[y][x + 1];
        max = max > result ? max : result;
    }


    //ㅏ
    if (y >= 1 && y < (N - 1) && x < (M - 1)){
        result = board[y - 1][x] + board[y][x] + board[y][x + 1] + board[y + 1][x];
        max = max > result ? max : result;
    }
    
    //ㅜ
    if (x  >= 1 && y < (N - 1) && x < (M - 1)){
        result = board[y][x - 1] + board[y][x] + board[y + 1][x] + board[y][x + 1];
        max = max > result ? max : result;
    }

    //ㅓ
    if (y >= 1 && y < (N-1) && x >= 1){
        result = board[y - 1][x] + board[y][x] + board[y][x - 1] + board[y + 1][x];
        max = max > result ? max : result;
    }

    return result; //ERROR : 여기가 틀렸었다!!(max를 반환해야함), 같은 이유로 약 2개가량 더 틀렸음

}





int main(){
    
    scanf("%d", &N);
    scanf("%d", &M);

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int temp;
            scanf("%d", &temp);
            board[i][j] = temp;
        }
    }


    //초기화 끝


    int result = 0;
    int max = 0;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            visited[i][j] = 1;
            result =  DFS(i,j,1);
            max = max > result ? max : result;
            visited[i][j] = 0;

            result = Another(i,j);
            max = max > result ? max : result;
        }

    printf("%d", max);

    return 0;

}