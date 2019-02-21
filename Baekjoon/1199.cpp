#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
#define NOT 0
using namespace std;

vector< vector<short> > graph_matrix;
vector<short> path;
stack<short> graph_stack;




void DFS(int now) {
	for(int next = 1; next<graph_matrix.size(); next++)
		while (graph_matrix[now][next] > 0) {
			graph_matrix[now][next]--;
			graph_matrix[next][now]--;
			DFS(next);
		}
	path.push_back(now);
}



int main() {

	vector<short> degree;
	int start_point = 0;
	int N;
	int edges = 0;


	int row;
	int col;

	scanf("%d", &N);
	graph_matrix.resize(N + 1);
	degree.resize(N + 1);
	fill(degree.begin(), degree.end(), 0);

	//Set value
	for (int i = 1; i <= N; i++) {
		graph_matrix[i].resize(N + 1);
		fill(graph_matrix[i].begin(), graph_matrix[i].end(), 0);

		for (int j = 1; j <= N; j++) {
			int temp;
			scanf("%d", &temp);
			graph_matrix[i][j] = temp;
			degree[i] += temp;
			edges += temp;
		}
	}

	int even = 0;
	int odd = 0;

	for (int i = 1; i < degree.size(); i++) {

		if (degree[i] % 2) 
			odd++;

		else
			even++;
	}


	if ( odd >= 1){
		printf("-1");
		return 0;
	}


	int start = 0;

	//Find first stack element
	for (row = 1; row <= N; row++) {
		for (col = 1; col <= N; col++)
			if (graph_matrix[row][col] != NOT) break;
		if (graph_matrix[row][col] != NOT) break;
	}


	start = row;

	//DFS
	//DFS(start);

	// while (!graph_stack.empty()) {
	// 	pair<short, short> prev_now_vertex = graph_stack.top();
	// 	graph_stack.pop();

	// 	if (graph_matrix[prev_now_vertex.first][prev_now_vertex.second] > NOT) {
	// 		graph_matrix[prev_now_vertex.first][prev_now_vertex.second] -=1;
	// 		graph_matrix[prev_now_vertex.second][prev_now_vertex.first] -=1;
	// 		path.push_back(prev_now_vertex.first);

	// 		if (path.size() == edges / 2 && prev_now_vertex.second == start)
	// 			path.push_back(prev_now_vertex.second);

	// 		for (int i = 1; i <= N; i++) {
	// 			if (graph_matrix[prev_now_vertex.second][i] > NOT) {
	// 				for (int j = 0; j < graph_matrix[prev_now_vertex.second][i]; j++) graph_stack.push(make_pair(prev_now_vertex.second, i));
	// 			}
	// 		}
	// 	}
	// }


	if (path.size() != edges/2 + 1) {
		printf("-1");
		return 0;
	}

	printf("%d", path[0]);

	for (int i = 1; i < path.size(); i++)
		printf(" %d", path[i]);


	return 0;

}