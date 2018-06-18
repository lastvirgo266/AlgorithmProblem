#include<stdio.h>
#include<vector>
#define RED 0
#define GREEN 1
#define BLUE 2
using namespace std;

int dp[3][1000] = { {0,}, };
inline int Min(int a, int b) { return a < b ? a : b; }
inline int NextColor(int nowColor) { if (nowColor == BLUE) return RED; else if (nowColor == BLUE + 1) return GREEN; else return nowColor + 1; }

vector< vector<int> > colorValue;

int SearchMin(int nowColor, int number)
{


	if (number == colorValue[nowColor].size() - 1)
		return colorValue[nowColor][number];

	if (dp[nowColor][number])
		return dp[nowColor][number];


	int min = 99999999;

	min = Min ( colorValue[nowColor][number] + SearchMin(NextColor(nowColor), number + 1), colorValue[nowColor][number] + SearchMin(NextColor(nowColor + 1), number + 1));
	dp[nowColor][number] = min;

	return min;

}




int main()
{
	int N;

	scanf("%d", &N);

	colorValue.resize(3);
	colorValue[0].resize(N);
	colorValue[1].resize(N);
	colorValue[2].resize(N);

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			int value;
			scanf("%d", &value);
			colorValue[i][j] = value;
		}

	}

	int min = 99999999;

	min = Min(SearchMin(RED, 0), SearchMin(GREEN, 0));
	min = Min(min, SearchMin(BLUE, 0));

	printf("%d",min);



	return 0;




}