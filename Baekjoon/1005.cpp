#include <iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
inline int Max(int a, int b){ return a > b ? a : b; }



class Node
{
public:
	vector<int> next_number;
	vector<int> prev_number;
	map<int, int> root_time;

	int this_number;
	int time = 0;
	double total_time = 0;

	void SumTotalTime();
	bool CheckRoot(map<int, int> prev_node);
	void ConnectRoot(map<int, int> prev_node);
	void NextTotalCheck(int now_index);

}; vector<Node> node;

void Node::SumTotalTime()
{
	map<int, int>::iterator itr;
	total_time = 0;

	for (itr = root_time.begin(); itr != root_time.end(); itr++)
	{
		total_time += itr->second;
	}

	total_time += time;


}

bool Node::CheckRoot(map<int, int> now_node)
{
	map<int, int>::iterator itr;

	for (itr = now_node.begin(); itr != now_node.end(); itr++)
		if (root_time.find(itr->first)->second)
			return true;

	return false;


}

void Node::NextTotalCheck(int now_index)
{
	for (int i = 0; i < node[now_index].next_number.size(); i++)
	{
		int next = node[now_index].next_number[i];

		if (node[next].total_time < (node[now_index].total_time + node[next].time))
		{

			node[next].total_time = node[now_index].total_time + node[next].time;
			NextTotalCheck(next);

		}
	}

}

void Node::ConnectRoot(map<int, int> now_node)
{
	map<int, int>::iterator itr;
	double temp_total_time = 0;

	for (itr = now_node.begin(); itr != now_node.end(); itr++)
	{
		if (root_time.find(itr->first)->first)
		{
			root_time[itr->first] = Max(itr->second, root_time[itr->first]);
			temp_total_time += root_time[itr->first];

		}

		else
		{
			root_time[itr->first] = itr->second;
			temp_total_time += itr->second;
		}


	}
	temp_total_time += time;

	if (temp_total_time > total_time)
	{
		total_time = temp_total_time;

		for (int i = 0; i < next_number.size(); i++)
		{
			int next = next_number[i];

			if (node[next].total_time > total_time + node[next].time)
				NextTotalCheck(next);
			

		}

	}




}





void Connect(int prev_node_index, int next_node_index)
{
	node[prev_node_index].next_number.push_back(next_node_index);
	node[next_node_index].prev_number.push_back(prev_node_index);


	//Calculate toatl_time
	if (node[prev_node_index].prev_number.size() == 0)
	{
		node[prev_node_index].total_time = node[prev_node_index].time;
		node[prev_node_index].root_time[prev_node_index] = node[prev_node_index].total_time;
	}

	//add code
	if (node[next_node_index].next_number.size() != 0 || (node[next_node_index].prev_number.size() != 0))
	{


		
		node[next_node_index].ConnectRoot(node[prev_node_index].root_time);
		/*
		if (!(node[next_node_index].CheckRoot(node[prev_node_index].root_time)))
		{
	


		}


		if (node[next_node_index].prev_number.size() == 0)
		{
			node[next_node_index].total_time += node[prev_node_index].total_time;

		}


		if (node[next_node_index].total_time < (node[prev_node_index].total_time + node[next_node_index].time))
		{

			node[next_node_index].total_time = node[prev_node_index].total_time + node[next_node_index].time;
			NextTotalCheck(next_node_index);
		}*/
	}

	else
	{
		node[next_node_index].total_time = Max(node[next_node_index].total_time, node[prev_node_index].total_time + node[next_node_index].time);
		node[next_node_index].root_time[prev_node_index] = node[prev_node_index].total_time;

	}





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



		int pre_prev = 1;
		int prev;
		int next = 0;

		// Set build flow
		for (int i = 1; i <= K; i++)
		{

			scanf("%d", &prev);
			scanf("%d", &next);
			//build_flow[i].first = prev;
			//build_flow[i].second = next;

			Connect(prev, next);


		}

		//sort(build_flow.begin(), build_flow.end());

	//	for (int i = 1; i <= K; i++)
	//		Connect(build_flow[i].first, build_flow[i].second);

		//Search 
		int win_build;
		scanf("%d", &win_build);
		val.push_back(node[win_build].total_time);


		node.clear();
		i++;
	}//End of While

	for (int i = 0; i < val.size(); i++)
		cout << val[i] << endl;

	return 0;
}