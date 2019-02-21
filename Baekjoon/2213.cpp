#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int weight[10001];
vector<int> matrix_adj[10001];
vector<int> ans;
int dp[10001][2];

void DFS(int cur, int prev){
	dp[cur][1] = weight[cur];
	for(int i=0; i<matrix_adj[cur].size(); i++){
		int nxt = matrix_adj[cur][i];
		if(nxt == prev) continue;
		DFS(nxt,cur);
		dp[cur][1] += dp[nxt][0];
		dp[cur][0] += max(dp[nxt][0], dp[nxt][1]);
	}
}

void rec(int cur, int color, int prev){
	if(color)ans.push_back(cur);
	for(int i=0; i<matrix_adj[cur].size();i++){
		int nxt = matrix_adj[cur][i];
		if(nxt == prev) continue;
		if(color) rec(nxt,0,cur);
		else{
			if(dp[nxt][0]<dp[nxt][1])rec(nxt,1,cur);
			else rec(nxt,0,cur);
		}
	}
}


int main(){
	 scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&weight[i]);
	
    for(int i=1;i<n;++i){
        int a,b;
        scanf("%d %d",&a,&b);
        matrix_adj[a].push_back(b);
        matrix_adj[b].push_back(a);
    }

    DFS(1,-1);
    int color=0;
    if(dp[1][0]<dp[1][1])
        color=1;

    rec(1,color,-1);
    sort(ans.begin(),ans.end());
    printf("%d\n",max(dp[1][0],dp[1][1]));
    for(int i=0;i<ans.size()-1;++i) printf("%d ",ans[i]);
	printf("%d",ans[ans.size()-1]);
}

//참고 : https://fatc.club/2017/03/01/568
