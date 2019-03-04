#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;
const int v_ = 1e4 + 1;

int v, e, cnt, pos, stk[v_];
bool vst[v_];
vi gp1[v_], gp2[v_];
vector<vi> res;

void dfs(int now) {
	vst[now] = true;
	for (int nxt : gp1[now]) if (!vst[nxt])
		dfs(nxt);
	stk[pos++] = now;
	//printf("%d ",now); //TEST
}

void scc(int now) {
	vst[now] = true;
	//printf("now : %d\n",now);
	res[cnt].push_back(now);
	for (int nxt : gp2[now]) if (!vst[nxt])
		scc(nxt);

}

int main() {
	int i;
	
	scanf("%d %d", &v, &e);
	for (i = 1; i <= e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		gp1[a].push_back(b);
		gp2[b].push_back(a);
	}

	for (i = 1; i <= v; i++)
		if (!vst[i]) dfs(i);
	memset(vst, 0, sizeof(vst));
	while (pos) {
		int top = stk[--pos];
		if (vst[top]) continue;
		res.push_back(vi());
		scc(top);
		cnt++;
	}

	for (i = 0; i < cnt; i++) sort(res[i].begin(), res[i].end());
	sort(res.begin(), res.end(), [](const vi &i, const vi &j) { return i[0] < j[0]; });
	
	printf("%d\n", res.size());
	for (auto &i : res) {
		for (auto j : i) printf("%d ", j);
		puts("-1");
	}

	return 0;
}