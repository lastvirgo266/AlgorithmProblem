#include<stdio.h>
#include<vector>
#include<map>
#define SEARCHING 0
#define SEARCHED 1
using namespace std;

int main()
{
	int T;
	vector<int> permu;
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int N;
		int count = 0;
		int searched = 0;
		int cycle[1001] = { 0, };
		map<int, int> graph;
		scanf("%d", &N);

		for (int i = 1; i <= N; i++)
		{
			int number;
			scanf("%d", &number);
			graph[i] = number;
		}

		for (int i = 1; searched != N; i++)
		{
			if (cycle[i] == SEARCHING)
			{
				cycle[i] = SEARCHED;
				searched++;

				int temp;
				temp = graph[i];

				while (cycle[temp] != SEARCHED)
				{
					cycle[temp] = SEARCHED;
					temp = graph[temp];
					searched++;
				}

				count++;

			}

		}
		permu.push_back(count);

	}//T End

	for (int i = 0; i < permu.size(); i++)
		printf("%d\n", permu[i]);

	return 0;

}