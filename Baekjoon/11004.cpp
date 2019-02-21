#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int N;
	int K;
	scanf("%d", &N);
	scanf("%d", &K);
	vector<long long> A;

	for (int i = 0; i < N; i++) {
		long long temp;
		scanf("%lld", &temp);
		A.push_back(temp);
	}

	sort(A.begin(), A.end());
	printf("%lld", A[K-1]);

	return 0;
}