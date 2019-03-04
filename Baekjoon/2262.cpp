#include<iostream>
#include<vector>
#define INF 260
using namespace std;

inline int max(int a, int b){ return a>b ? a:b;}


int main() {
    int ans=0;
    vector<int> tnament;
    tnament.resize(INF);
    fill(tnament.begin(),tnament.end(), 0);
    int n;

    cin>>n;
    for(int i=1; i<=n; i++) cin>>tnament[i];

    for(int i=n; i>1; i--){
        int j;
        for(j=1; j<=n; j++) if(tnament[j] == i) break;
        ans += tnament[j] - max(tnament[j-1], tnament[j+1]);
        for(; j<=n; j++) tnament[j] = tnament[j+1];
    }
    cout<<ans;

	return 0;
}



//Ref : http://wookje.dance/2017/03/17/boj-2262-%ED%86%A0%EB%84%88%EB%A8%BC%ED%8A%B8-%EB%A7%8C%EB%93%A4%EA%B8%B0/