#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define IS 1
#define SEARCHED 2
#define NOT 0

int Only(int graph[][50], int H, int W)
{
	int people = 0;
	int i;
	int j;

	//Find start point
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			if (graph[i][j] == IS)
			{
				people++;
				break;
			}
		}
		if (j < W && graph[i][j] == IS)
			break;
	}

	if (people == 0)
		return 0;

	people--;

	queue< pair<int, int> > only_queue;

	only_queue.push(make_pair(i, j));

	while (!only_queue.empty())
	{
		pair<int, int> point = only_queue.front();
		only_queue.pop();


		if (point.first >= 0 && point.second >= 0 && point.first < H && point.second < W && graph[point.first][point.second] == IS)
		{
			people++;
			graph[point.first][point.second] = SEARCHED;

			if (point.first + 1 >= 0 && point.second >= 0 && point.first + 1 < H && point.second < W && graph[point.first + 1][point.second] == IS)
				only_queue.push(make_pair(point.first + 1, point.second));

			if (point.first - 1 >= 0 && point.second >= 0 && point.first - 1 < H && point.second < W && graph[point.first - 1][point.second] == IS)
				only_queue.push(make_pair(point.first - 1, point.second));

			if (point.first >= 0 && point.second + 1 >= 0 && point.first < H && point.second + 1 < W && graph[point.first][point.second + 1] == IS)
				only_queue.push(make_pair(point.first, point.second + 1));

			if (point.first >= 0 && point.second - 1 >= 0 && point.first < H && point.second - 1 < W && graph[point.first][point.second - 1] == IS)
				only_queue.push(make_pair(point.first, point.second - 1));



			if (point.first + 1 >= 0 && point.second - 1 >= 0 && point.first + 1 < H && point.second - 1 < W && graph[point.first + 1][point.second - 1] == IS)
				only_queue.push(make_pair(point.first + 1, point.second - 1));

			if (point.first - 1 >= 0 && point.second - 1 >= 0 && point.first - 1 < H && point.second - 1 < W && graph[point.first - 1][point.second - 1] == IS)
				only_queue.push(make_pair(point.first - 1, point.second - 1));

			if (point.first + 1 >= 0 && point.second + 1 >= 0 && point.first + 1 < H && point.second + 1 < W && graph[point.first + 1][point.second + 1] == IS)
				only_queue.push(make_pair(point.first + 1, point.second + 1));

			if (point.first - 1 >= 0 && point.second + 1 >= 0 && point.first - 1 < H && point.second + 1 < W && graph[point.first - 1][point.second + 1] == IS)
				only_queue.push(make_pair(point.first - 1, point.second + 1));
		}
	}

	return people;

}


int main()
{
	int W, H;
	int land_count = 0;
	int temp;
	int graph[50][50] = { 0 };
	vector<int> onlyLand;

	while (1)
	{


		scanf("%d", &W);
		scanf("%d", &H);

		if (W == 0 && H == 0)
			break;


		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				int number;
				scanf("%d", &number);
				graph[i][j] = number;
			}
		}

		do
		{
			temp = Only(graph, H, W);

			if (temp != 0)
				land_count++;
			else
				break;

		} while (temp != 0);

		onlyLand.push_back(land_count);
		land_count = 0;

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				graph[i][j] = 0;
	}

	for (int i = 0; i < onlyLand.size(); i++)
		printf("%d\n", onlyLand[i]);

	return 0;

}