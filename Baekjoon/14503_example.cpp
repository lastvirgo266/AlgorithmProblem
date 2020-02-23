#include <iostream>
#include<stdio.h>


using namespace std;

#define MAX_SIZE 51

// 바라보는 방향(북, 동, 남, 서)
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

// 바라보는 방향에 따른 후진 (남, 서, 북, 동)
int back_dx[4] = { 1,0,-1,0 };
int back_dy[4] = { 0,-1,0,1 };

int ans; // 로봇청소기가 청소하는 칸의 개수
int map[MAX_SIZE][MAX_SIZE];
int n, m; // 영역의 크기
int r, c, d; // 로봇청소기의 좌표(r,c), 바라보는 방향(d) : 북(0), 동(1), 남(2), 서(3)


void Test(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ",map[i][j]);
        }

        printf("\n");
    }

    printf("\n\n\n");
}


void Dfs(int x, int y, int direction)
{
    // 벽이면 끝
    if (map[x][y] == 1) return;

    // 빈 칸이면 청소한다.
    if (map[x][y] == 0)
    {
        map[x][y] = 2;
        ans++;
        Test();

        if(ans == 20){
            exit;
        }
    }

    // 네 방향 검사
    for (int k = 0; k < 4; k++)
    {
        // 북(0) -> 서(3), 동(1) -> 북(0), 남(2) -> 동(1), 서(3) -> 남(2)
        int next_direction = direction-1 < 0 ? 3 : direction-1;
        int next_x = x + dx[next_direction], next_y = y + dy[next_direction];

        // 빈 칸이면 청소
        if (map[next_x][next_y] == 0)
        {
            Dfs(next_x, next_y, next_direction);
            // 다음 칸으로 넘어간 경우에 더 이상 나머지 방향을 검사하지 않는다.
            return;
        }
        // 청소했거나 벽이면 방향만 바꿔준다.
        else
        {
            direction = next_direction;
        }
    }
    // 검사 끝

    // 네 방향 모두 청소했거나 벽이면 방향을 유지한채로 후진한다.
    int next_x = x + back_dx[direction], next_y = y + back_dy[direction];

    Dfs(next_x, next_y, direction);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    cin >> r >> c >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    Dfs(r, c, d);

    cout << ans << "\n";

    return 0;
}