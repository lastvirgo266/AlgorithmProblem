#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;


typedef struct _graph
{
	int vertex;
	vector<int> e_set;
}graph;



int main()
{
	int K;
	scanf("%d", &K);
	vector<string> output;

	for (int j = 1; j <= K; j++)
	{
		//Main start
		int V, E;
		scanf("%d", &V);
		scanf("%d", &E);
		vector<graph> arr_graph;
		vector<int> vertex_visit_table;
		arr_graph.resize(V+1);
		vertex_visit_table.resize(V + 1);
		fill(vertex_visit_table.begin(), vertex_visit_table.end(), -1);//vertex_visit_talbe √ ±‚»≠


		//Set Graph
		for (int i = 1; i <= E; i++)
		{
			int v;
			int e;

			scanf("%d", &v);
			scanf("%d", &e);
			arr_graph[v].e_set.push_back(e);
			arr_graph[e].e_set.push_back(v);

			arr_graph[v].vertex = -1;
			arr_graph[e].vertex = -1;

			vertex_visit_table[v] = 0;
			vertex_visit_table[e] = 0;

		}

		//Big(O) : ??

		//Pre set value
		queue<int> bfs_queue;
		string value = "";
		vector<int> apart_vertex;





		//Pre set
		int first_vertex;
		for (int i = 1; i < vertex_visit_table.size(); i++) {

			if (vertex_visit_table[i] == 0) {
				first_vertex = i;
				break;
			}

		}

		for (int i = 0; i < arr_graph[first_vertex].e_set.size(); i++)
		{
			int next_vertex = arr_graph[first_vertex].e_set[i];
			bfs_queue.push(next_vertex);
			arr_graph[next_vertex].vertex = 2;
			vertex_visit_table[next_vertex] = 1;

		}
		arr_graph[first_vertex].vertex = 1;
		vertex_visit_table[first_vertex] = 1;
		int prev_vertex = first_vertex;



		while (!bfs_queue.empty())
		{
			int now_vertex = bfs_queue.front();
			bfs_queue.pop();

			//now_vertex value 1
			if (arr_graph[now_vertex].vertex == 1)
			{
				for (int i = 0; i < arr_graph[now_vertex].e_set.size(); i++)
				{
					int next_vertex = arr_graph[now_vertex].e_set[i];

					if(vertex_visit_table[next_vertex] == 0)
						bfs_queue.push(next_vertex);

					vertex_visit_table[next_vertex] = 1;

					if (arr_graph[next_vertex].vertex != 1)
						arr_graph[next_vertex].vertex = 2;

					else if (next_vertex == now_vertex)
						arr_graph[next_vertex].vertex = arr_graph[now_vertex].vertex;

					else
					{
							value = "NO";
							break;
					}

				}
			}

			//now_vertex value 2
			else
			{

				for (int i = 0; i < arr_graph[now_vertex].e_set.size(); i++)
				{
					int next_vertex = arr_graph[now_vertex].e_set[i];

					if (vertex_visit_table[next_vertex] != 1)
						bfs_queue.push(next_vertex);

					vertex_visit_table[next_vertex] = 1;

					if (arr_graph[next_vertex].vertex != 2)
						arr_graph[next_vertex].vertex = 1;

					else if (next_vertex == now_vertex)
						arr_graph[next_vertex].vertex = arr_graph[now_vertex].vertex;

					else
					{
						value = "NO";
						break;
					}

				}

			}

			if (value.compare("") != 0)
				break;
			
			prev_vertex = now_vertex;

			//Find apart vertex
			if (bfs_queue.empty())
			{
				if(apart_vertex.size() == 0)
					for (int i = 1; i < vertex_visit_table.size(); i++)
					{
						if (vertex_visit_table[i] == 0)
							apart_vertex.push_back(i);
					}

				if(apart_vertex.size() != 0)
				{
					for (int i = 0; i < apart_vertex.size(); i++)
					{

						if (vertex_visit_table[apart_vertex[i]] == 0)
						{
							int temp = apart_vertex[i];


							for (int i = 0; i < arr_graph[temp].e_set.size(); i++)
							{
								int next_vertex = arr_graph[temp].e_set[i];
								bfs_queue.push(next_vertex);
								arr_graph[next_vertex].vertex = 2;
								vertex_visit_table[next_vertex] = 1;

							}
							prev_vertex = temp;
							arr_graph[temp].vertex = 1;
							vertex_visit_table[temp] = 1;

							break;
						}

					}


				}


			}//END Find Vertex



		}//END QUEUE

		if (value.compare("NO") == 0);
		else value = "YES";

		output.push_back(value);



	}//END TEST CASE

	for (int i = 0; i < output.size(); i++)
		cout << output[i] << endl;

	return 0;



}