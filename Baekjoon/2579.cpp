//#include<stdio.h>
//#include<vector>
//
//#define NEXT 1
//#define JUMP 2
//#define OVER 4
//using namespace std;
//inline int Max(int a, int b) { return a > b ? a : b; }
//
//vector<int> stage;
//
//int dp[300][2] = { {0}, };
//
//
//int Search(int nowStage, int stageState, int nowScore)
//{
//
//	if (stageState == OVER)
//		return 0;
//
//	if (nowStage <= -1)
//	{
//		return nowScore;
//	}
//
//	if (dp[nowStage][stageState - 1])
//		return dp[nowStage][stageState - 1] + nowScore;
//	
//
//
//	int max = 0;
//
//	if (stageState == 2)
//		max = Max(max,Search(nowStage - JUMP, 1, nowScore + stage[nowStage]));
//
//	else
//	{
//		max = Max(max, Search(nowStage - JUMP, 1, nowScore + stage[nowStage]));
//		max = Max(max, Search(nowStage - NEXT, stageState + NEXT, nowScore + stage[nowStage]));
//	}
//
//	
//
//
//	dp[nowStage][stageState - 1] = max - nowScore; //nowScore¸¦ »©´Â°Ô ÇÙ½ÉÀÌ¿´´Ù!!
//
//
//	return max;
//
//}
//
//
//
//int main()
//{
//	int stageNumber;
//	scanf("%d", &stageNumber);
//	stage.resize(stageNumber);
//
//
//	for(int i=0; i<stage.size(); i++)
//	{
//		int number;
//		scanf("%d", &number);
//		stage[i] = number;
//	}
//		
//
//
//
//
//
//	int max = Search(stage.size() - 1, 1, 0);
//
//	printf("%d", max);
//
//
//	return 0;
//
//
//
//}



#include <iostream>
#include <algorithm>
#include <vector>


inline int MAX(int a, int b) { return a > b ? a : b; }

using namespace std;
int main()
{
	int max = -1;

	int n;
	cin >> n;
	vector<int> a(n);

	int d[300][2];

	for (int i = 0; i<n; i++)
	{
		cin >> a[i];
		d[i][0] = 0;
		d[i][1] = 0;
	}

	d[n - 1][0] = a[n - 1];
	d[n - 1][1] = a[n - 1];
	d[n - 2][0] = 0;
	d[n - 2][1] = 0;


	for (int i = n-1; i>=3; i--)
	{

		int one = i - 1;
		int two = i - 2;
		int three = i - 3;

		//New Algorithm
		d[one][1] = a[one] + d[i][0];
		d[two][0] = a[two] + MAX(d[i][0], d[i][1]);
		d[three][0] = MAX(d[one][0], d[one][1]) + a[three];
		d[three][1] = d[two][0] + a[three];
		
		//if (one >= 0 && d[i][COUNT] < 2 && (d[one][VAL] < (a[one]+d[i][VAL])))
		//{
		//	d[one][VAL] = a[one] + d[i][VAL];
		//	d[one][COUNT] = d[i][COUNT] + 1;
		//}
		//

		//if (two >= 0 && (d[two][VAL] < (a[two] + d[i][VAL])))
		//{
		//	d[two][VAL] = a[two] + d[i][VAL];
		//	d[two][COUNT] = 1;
		//}


	}


	max = MAX(MAX(d[0][0], d[0][1]),d[1][1]);
	

	cout << max << endl;
	//cout << *max_element(d.begin(), d.end()) << '\n';
	return 0;
}
