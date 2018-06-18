#include<stdio.h>
#include<vector>
using namespace std;

vector< vector<int> > dp;


int FindLatt(int x, int y)
{

	int val = 0;

	if (dp[x][y])
		return dp[x][y];

	if ((x == 1) || (y == 1))
		return 1;

	else if (y == 2)
		return x ;

	else if (x == 2)
		return y;



	for (int i = y; i >= 2; i--)
	{
		val += FindLatt(x-1, i);
	}
	
	val += 1;

	dp[x][y] = val;

	return val;


}



int main()
{
	int x;
	int y;
	int circleNumber;
	int circleX;
	int circleY;

	dp.resize(16);
	for (int i = 1; i <= 15; i++)
		dp[i].resize(16);

	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &circleNumber);

	if (circleNumber != 0)
	{
		if (circleNumber % y != 0)
		{
			circleX = circleNumber / y + 1;
			circleY = circleNumber % y;
		}

		else
		{
			circleX = circleNumber / y;
			circleY = y;
		}

		int valCircle = 1;
		int valDesti = 1;

		valCircle = FindLatt(circleX, circleY);
		valDesti = FindLatt(x - circleX + 1, y - circleY + 1);


		printf("%d", valCircle*valDesti);

	}
	
	else
		printf("%d", FindLatt(x, y));



	return 0;

}