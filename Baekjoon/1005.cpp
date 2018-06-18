#include <iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
inline int Max(int a, int b){ return a > b ? a : b; }
double total_time = 0;


class Node
{
public:
	vector<int> next_number;
	vector<int> prev_number;

	int time = 0;


}; vector<Node> node;






void Connect(int prev_node_index, int next_node_index)
{
	node[prev_node_index].next_number.push_back(next_node_index);
	node[next_node_index].prev_number.push_back(prev_node_index);
}


int main()
{
	int T;
	cin >> T;
	int i = 1;
	vector<double> val;
	vector< pair<int, int> > build_flow;

	while (i <= T)
	{
		int N;
		scanf("%d", &N);

		//Not use '0'index
		node.resize(N + 1);

		int K;
		cin >> K;

		//build_flow.resize(K + 1);

		// Set time
		for (int i = 1; i <= N; i++)
		{
			int time;
			scanf("%d", &time);
			node[i].time = time;
		}

		int prev;
		int next;

		// Set build flow
		for (int i = 1; i <= K; i++)
		{

			scanf("%d", &prev);
			scanf("%d", &next);

			Connect(prev, next);


		}

		//Search 
		int win_build;
		scanf("%d", &win_build);


		node.clear();
		i++;
	}//End of While

	for (int i = 0; i < val.size(); i++)
		cout << val[i] << endl;

	return 0;
}