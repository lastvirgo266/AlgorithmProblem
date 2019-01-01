#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define IS 1
#define SEARCHED 2
#define NOT 0

int Only(int graph[][25], int max)
{
	int people = 0;
	int i;
	int j;

	//Find start point
	for (i = 0; i < max; i++)
	{
		for (j = 0; j < max; j++)
		{
			if (graph[i][j] == IS)
			{
				people++;
				break;
			}
		}
		if (j<max && graph[i][j] == IS)
			break;
	}

	if (people == 0)
		return 0;

	queue< pair<int, int> > only_queue;
	graph[i][j] = SEARCHED;

	only_queue.push(make_pair(i+1, j));
	only_queue.push(make_pair(i, j+1));

	while (!only_queue.empty())
	{
		pair<int, int> point = only_queue.front();
		only_queue.pop();


		if (point.first>=0 && point.second>=0 && point.first < max && point.second < max && graph[point.first][point.second] == IS)
		{
			people++;
			graph[point.first][point.second] = SEARCHED;

			if (point.first+1 >= 0 && point.second >= 0 && point.first+1 < max && point.second < max && graph[point.first + 1][point.second] == IS)
				only_queue.push(make_pair(point.first + 1, point.second));

			if (point.first-1 >= 0 && point.second >= 0 && point.first-1 < max && point.second < max && graph[point.first - 1][point.second] == IS)
				only_queue.push(make_pair(point.first - 1, point.second));

			if (point.first >= 0 && point.second+1 >= 0 && point.first < max && point.second+1 < max && graph[point.first][point.second + 1] == IS)
				only_queue.push(make_pair(point.first, point.second + 1));

			if (point.first >= 0 && point.second-1 >= 0 && point.first < max && point.second-1 < max && graph[point.first][point.second - 1] == IS)
				only_queue.push(make_pair(point.first, point.second - 1));
		}
	}

	return people;

}


int main()
{
	int N;
	int onlyCount = 0;
	int temp = 0;
	int graph[25][25] = { 0 };
	vector<int> onlyPeople;

	scanf("%d", &N);

	char c;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> c;

			if (c == '1')
				graph[i][j] = 1;
		}
	}

	do
	{
		temp = Only(graph, N);

		if (temp != 0)
		{
			onlyCount++;
			onlyPeople.push_back(temp);
		}

		else
			break;

	} while (temp != 0);

	sort(onlyPeople.begin(), onlyPeople.end());

	printf("%d\n", onlyCount);

	for (int i = 0; i < onlyPeople.size(); i++)
		printf("%d\n", onlyPeople[i]);

	return 0;

}