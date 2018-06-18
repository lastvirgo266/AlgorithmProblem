#include<stdio.h>
#include<vector>

#define NEXT 1
#define JUMP 2
#define OVER 4
using namespace std;
inline int Max(int a, int b) { return a > b ? a : b; }

vector<int> stage;

int dp[300][2] = { {0}, };


int Search(int nowStage, int stageState, int nowScore)
{

	if (stageState == OVER)
		return 0;

	if (nowStage <= -1)
	{
		return nowScore;
	}

	if (dp[nowStage][stageState - 1])
		return dp[nowStage][stageState - 1] + nowScore;
	


	int max = 0;

	if (stageState == 2)
		max = Max(max,Search(nowStage - JUMP, 1, nowScore + stage[nowStage]));

	else
	{
		max = Max(max, Search(nowStage - JUMP, 1, nowScore + stage[nowStage]));
		max = Max(max, Search(nowStage - NEXT, stageState + NEXT, nowScore + stage[nowStage]));
	}

	


	dp[nowStage][stageState - 1] = max - nowScore; //nowScore¸¦ »©´Â°Ô ÇÙ½ÉÀÌ¿´´Ù!!


	return max;

}



int main()
{
	int stageNumber;
	scanf("%d", &stageNumber);
	stage.resize(stageNumber);


	for(int i=0; i<stage.size(); i++)
	{
		int number;
		scanf("%d", &number);
		stage[i] = number;
	}
		





	int max = Search(stage.size() - 1, 1, 0);

	printf("%d", max);


	return 0;



}