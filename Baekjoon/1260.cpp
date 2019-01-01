//#include<stdio.h>
//#include<vector>
//
//#define IS 1
//#define NOT 0
//#define SEARCHED 2
//using namespace std;
//short graph[1001][1001] = { {0,}, };
//short node[1001] = { IS, };
//
//
//
//void DFS(int start_v, int max_v, vector<short> *buf)
//{
//	if (graph[start_v][start_v] == IS)
//	{
//		graph[start_v][start_v] = SEARCHED;
//		buf->push_back(start_v);
//	}
//
//
//	for (int i = 1; i <= max_v; i++)
//	{
//		if (graph[start_v][i] == IS && node[i] == IS)
//		{
//			graph[start_v][i] = SEARCHED;
//			graph[i][start_v] = SEARCHED;
//			graph[start_v][start_v] = SEARCHED;
//			graph[i][i] = SEARCHED;
//			node[i] = SEARCHED;
//
//			buf->push_back(i);
//			DFS(i, max_v, buf);
//		}
//	}
//
//	return;
//
//}
//
//
//int main()
//{
//
//
//	int N;
//	int M;
//	int start_v;
//	int max_v;
//
//
//
//	vector<short> buf;
//	vector<short> dfs;
//	vector<short> bfs;
//
//
//	scanf("%d", &N);
//	scanf("%d", &M);
//	scanf("%d", &start_v);
//	max_v = N;
//
//	//Input
//	for (int i = 0; i < M; i++)
//	{
//		int v;
//		int e;
//
//		scanf("%d", &v);
//		scanf("%d", &e);
//		graph[v][e] = IS;
//		graph[e][v] = IS;
//		graph[v][v] = IS;
//		graph[e][e] = IS;
//
//	}
//
//
//	//DFS
//	for (int i = 1; i <= max_v; i++)
//	{
//		graph[start_v][start_v] = SEARCHED;
//		dfs.push_back(start_v);
//
//		if (graph[start_v][i] == IS && node[i] == IS)
//		{
//			graph[start_v][i] = SEARCHED;
//			graph[i][start_v] = SEARCHED;
//			graph[start_v][start_v] = SEARCHED;
//			graph[i][i] = SEARCHED;
//			node[i] = SEARCHED;
//
//
//			dfs.push_back(i);
//
//			DFS(i, max_v, &buf);
//		}
//
//
//		dfs.insert(dfs.end(), buf.begin(), buf.end());
//		buf.clear();
//
//	}
//
//
//	//BFS
//	graph[start_v][start_v] = SEARCHED;
//	bfs.push_back(start_v);
//
//	for (int j = 1; j <= max_v; j++)
//	{
//
//		if (graph[start_v][j] == IS)
//		{
//			int start_v = j;
//
//			if(graph[start_v][start_v] == IS)
//			{
//				graph[start_v][start_v] = SEARCHED;
//				bfs.push_back(start_v);
//			}
//
//
//
//			for (int i = 1; i <= max_v; i++)
//			{
//				if (graph[start_v][i] == IS)
//				{
//					graph[start_v][i] = SEARCHED;
//					graph[i][start_v] = SEARCHED;
//					bfs.push_back(i);
//				}
//			}
//
//		}
//
//	}
//
//
//	//Output
//	for (int i = 0; i < dfs.size(); i++)
//	{
//		printf("%d ", dfs[i]);
//	}
//
//	printf("\n");
//
//	for (int i = 0; i < bfs.size(); i++)
//	{
//		printf("%d ", bfs[i]);
//	}
//
//
//
//}




#include<stdio.h>
#include<queue>

#define IS 1
#define NOT 0

using namespace std;

int graph[1001][1001] = { 0, };
int dfs_buf[1001] = { 0 };
int bfs_buf[1001] = { 0, };
queue<int> bfs_queue;

//DFS
void DFS(int v, int max_v)
{
	dfs_buf[v] = 1;
	printf("%d ", v);


	for (int i = 1; i <= max_v; i++)
	{
		if (graph[v][i] == IS && dfs_buf[i] == NOT)
			DFS(i, max_v);
	}
}


//BFS
void BFS(int v, int max_v)
{
	int pop;

	printf("%d ", v);
	bfs_buf[v] = IS;
	bfs_queue.push(v);


	while (!bfs_queue.empty())
	{
		pop = bfs_queue.front();
		bfs_queue.pop();

		for (int i = 1; i <= max_v; i++)
		{
			if (graph[pop][i] == IS && bfs_buf[i] == NOT)
			{
				printf("%d ", i);
				bfs_queue.push(i);
				bfs_buf[i] = 1;
			}
		}



	}
	


}



int main()
{


	int N;
	int M;
	int start_v;
	int max_v;


	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%d", &start_v);
	max_v = N;

	//Input
	for (int i = 0; i < M; i++)
	{
		int v;
		int e;

		scanf("%d", &v);
		scanf("%d", &e);
		graph[v][e] = IS;
		graph[e][v] = IS;

	}

	//Output
	DFS(start_v, max_v);
	printf("\n");
	BFS(start_v, max_v);


	return 0;


}