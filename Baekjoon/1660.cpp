#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;


int dp[300001];

inline int Min(int a, int b) { return a < b ? a : b; }
inline int Stack(int stage) { int temp = 0; for (int i = 1; i <= stage; i++) temp += (i * (i + 1) / 2); return temp; }
inline int GetOptStage(int N) {
	int count = 0;
	int now_stage = pow(N, 1.0 / 3.0);

	do {

		if (Stack(now_stage) > N) {
			count++;
			now_stage--;
			break;
		}

		else
			now_stage++;

	} while (N > 0);


	return now_stage;

}

int main() {

	for (int i = 0; i <= 300000; i++)
		dp[i] = 300000;

	int N;
	int n;
	scanf("%d", &N);

	n = GetOptStage(N);


	for (int i = 1; i <= n; i++) {
		dp[Stack(i)] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = Stack(i); j <= N; j++) {
			dp[j] = Min(dp[j], dp[j - Stack(i)] + 1);
		}
	}

	printf("%d", dp[N]);
	
	return 0;


}