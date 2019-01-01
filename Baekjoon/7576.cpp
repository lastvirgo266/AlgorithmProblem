#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

#define FLOWER 1
#define TOMATO 0
#define NOT -1
queue< pair<int, int> > next_queue;

bool Flowering(int graph[][1000], pair<int, int> point, int N, int M)
{
	bool check = false;

	/*각각 위 아래 오른쪽 왼쪽을 검사, 검사해서 새로 FLOWER시킨 토마토의 좌표를 next_queue에 저장*/
	if (point.first + 1 >= 0 && point.second >= 0 && point.first + 1 < M && point.second < N && graph[point.first + 1][point.second] == TOMATO)
	{
		graph[point.first + 1][point.second] = FLOWER;
		next_queue.push(make_pair(point.first + 1, point.second));
		check = true;
	}

	if (point.first - 1 >= 0 && point.second >= 0 && point.first - 1 < M && point.second < N && graph[point.first - 1][point.second] == TOMATO)
	{
		graph[point.first - 1][point.second] = FLOWER;
		next_queue.push(make_pair(point.first - 1, point.second));
		check = true;
	}

	if (point.first >= 0 && point.second + 1 >= 0 && point.first < M && point.second + 1 < N && graph[point.first][point.second + 1] == TOMATO)
	{
		graph[point.first][point.second + 1] = FLOWER;
		next_queue.push(make_pair(point.first, point.second + 1));
		check = true;
	}

	if (point.first >= 0 && point.second - 1 >= 0 && point.first < M && point.second - 1 < N && graph[point.first][point.second - 1] == TOMATO)
	{
		graph[point.first][point.second - 1] = FLOWER;
		next_queue.push(make_pair(point.first, point.second - 1));
		check = true;
	}

	return check; //하나라도 FLOWER 시켰으면 true를반환
}

int Tomato(int graph[][1000], int N, int M)
{
	queue< pair<int, int> > tomato_queue;
	bool check = false;

	//처음 실행할땐 FLOWER한 토마토를 찾아서 토마토 큐에 집어 넣음
	if (next_queue.empty())
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
			{
				if (graph[i][j] == FLOWER)
					tomato_queue.push(make_pair(i, j));
			}
	//1회 이후 실행하고 나면 기존 FLOWER 토마토에 의해 새로 추가된 FLOWER 토마토만 큐들만 이용함(next_queue)
	else
		tomato_queue = next_queue;

	//next_queue 재활용을 위해 전부 pop 시켜줌
	while (!next_queue.empty())
		next_queue.pop();

	while (!tomato_queue.empty())
	{
		pair<int, int> point = tomato_queue.front();
		tomato_queue.pop();
		check = Flowering(graph, point, N, M) || check;//주변에 있는 TOMATO를 FLOWER 시키고 이미 전부 FLOWER 했으면 0을 반환
	}

	return check;
}

int main()
{
	int N, M;
	int graph[1000][1000] = { 0 };
	int count = 0;

	scanf("%d", &N);
	scanf("%d", &M);

	//INPUT
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			int temp;
			scanf("%d", &temp);
			graph[i][j] = temp;
		}

	//FLOWER
	while (Tomato(graph, N, M))
		count++;

	//만약 FLOWER 시킬수없는게 있었으면 -1 반환
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (graph[i][j] == 0)
				count = -1;

	printf("%d", count);
	return 0;
}