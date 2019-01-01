#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define IS 1
#define NOT 0

void Only(int graph[][101], int N, int M)
{
	queue< pair<int, int> > only_queue;
	int i, j;
	i = 1;
	j = 1;
	graph[i][j] = 1;
	only_queue.push(make_pair(i,j));

	while (!only_queue.empty())
	{
		pair<int, int> point = only_queue.front();
		only_queue.pop();


		if (point.first >= 0 && point.second >= 0 && point.first <=N && point.second <=M && graph[point.first][point.second] != NOT)
		{

			if (point.first + 1 >= 0 && point.second >= 0 && point.first + 1 <= N && point.second <= M && graph[point.first + 1][point.second] == IS)
			{
				graph[point.first + 1][point.second] += graph[point.first][point.second];
				only_queue.push(make_pair(point.first + 1, point.second));
			}

			if (point.first - 1 >= 0 && point.second >= 0 && point.first - 1 <= N && point.second <= M && graph[point.first - 1][point.second] == IS)
			{
				graph[point.first - 1][point.second] += graph[point.first][point.second];
				only_queue.push(make_pair(point.first - 1, point.second));
			}

			if (point.first  >= 0 && point.second+1 >= 0 && point.first  <= N && point.second+1 <= M && graph[point.first][point.second+1] == IS)
			{
				graph[point.first][point.second+1] += graph[point.first][point.second];
				only_queue.push(make_pair(point.first, point.second+1));
			}

			if (point.first >= 0 && point.second - 1 >= 0 && point.first <= N && point.second - 1 <= M && graph[point.first][point.second - 1] == IS)
			{
				graph[point.first][point.second - 1] += graph[point.first][point.second];
				only_queue.push(make_pair(point.first, point.second - 1));
			}
		}
	}

}

int main()
{
	int N, M;
	int graph[101][101] = { 0 };

	scanf("%d", &N);
	scanf("%d", &M);

	char c;

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++)
		{
			cin >> c;
			if (c == '1')
				graph[i][j] = 1;
		}
	
	Only(graph, N, M);
	printf("%d\n", graph[N][M]);

	return 0;

}