#include<stdio.h>
#define VAL 0
#define COUNT 1

inline int MAX(int a, int b) { return a > b ? a : b; }


int main()
{
	/*int dp[1000 + 1][2];
	int number[1000 + 1];
	int max = 0;


	dp[0][VAL] = 0;
	dp[0][COUNT] = 0;
	dp[1][VAL] = 0;
	dp[1][COUNT] = 0;


	int N;
	scanf("%d", &N);


	for (int i = 1; i <= N; i ++ )
	{
		int temp;
		scanf("%d", &temp);
		number[i] = temp;
	}

	dp[1][VAL] = number[1];
	dp[1][COUNT] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i][VAL] = number[i];
		dp[i][COUNT] = 1;


		for (int j = i; j >= 1; j--)
		{
			if (number[i] > dp[j][VAL])
			{
				dp[j][VAL] = number[i];
				dp[j][COUNT] += 1;
			}

			max = MAX(max, dp[j][COUNT]);
		}


	}

	printf("%d", max);*/


}