#include<stdio.h>
#include<vector>
using namespace std;


vector< vector<int> > memoi;
int N;


// 10844.cpp

int StageNumber(int digit, int number)
{
	if (memoi[digit][number])
		return memoi[digit][number];


	if (N == 1)
	{
		return 9;
	}


	else if (digit == N )
	{
		if ((number == 0) || (number == 9) || (number == 1))
			return 1;
		else
			return 2;

	}


	else if (digit == 1)
	{
		int ret = 0;

		for (int i = number; i < 10; i++)
		{

			ret += (StageNumber(digit + 1, i) % 1000000000);
			ret %= 1000000000;

		}

		return ret % 1000000000;

	}

	else
	{

		int ret = 0;

		if((number == 0) || (number == 9))
		{
			if ((number == 0))
				ret = (StageNumber(digit + 1, number + 1) % 1000000000);
			else
				ret = (StageNumber(digit + 1, number - 1) % 1000000000);


			ret %= 1000000000;

			memoi[digit][number] = ret;
			return ret;

		}


		else
		{
			ret += (StageNumber(digit + 1, number + 1) % 1000000000);
			ret %= 1000000000;
			ret += (StageNumber(digit + 1, number - 1) % 1000000000);
			ret %= 1000000000;


			memoi[digit][number] = ret;
			return ret;


		}



	}


}




int main()
{
	memoi.resize(100 + 1);

	for (int i = 1; i < memoi.size(); i++)
		memoi[i].resize(10);
	


	scanf("%d", &N);


	printf("%d", StageNumber(1, 0));





}

