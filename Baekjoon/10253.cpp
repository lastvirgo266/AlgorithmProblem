#include<stdio.h>
#include<iostream>
#include<time.h>
#include<vector>
#include<map>
using namespace std;

int denom;
int numer;


int CheckHenrry(int oneDenom)
{
		
	if (numer*oneDenom - denom < 0)
		return -1;
	

	else
	{
		
		numer = numer*oneDenom - denom;
		denom = denom*oneDenom;

		if(numer != 0)
			if ((denom % numer) == 0)
			{
				denom /= numer;
				numer = 1;
			}


		return numer;

	}


}



int FindHenrry()
{
	int oneDenom = 1;
	int result = CheckHenrry(oneDenom);

	while(result != 0)
	{
		oneDenom++;
		result = CheckHenrry(oneDenom);
	}


	return oneDenom;


}




int main()
{
	vector<int> result;
	

	/************************************************************************/

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &numer);
		scanf("%d", &denom);
		result.push_back(FindHenrry());

	}

	
	for (int i = 0; i < result.size(); i++)
		printf("%d\n", result[i]);




	/************************************************************************/






	return 0;

}





//vector< vector<short> > memoi;
//
//void SaveDivisor(int temp_denom)
//{
//
//	int count = 0;
//	vector<short> div;
//
//	if (memoi[temp_denom].size())
//		return;
//
//
//
//	for (int i = 1; i <= 10000; i++)
//	{
//
//		if (temp_denom % i == 0)
//		{
//			div.push_back(i);
//		}
//
//
//
//
//
//	}
//
//
//	memoi[temp_denom] = div;
//
//
//
//}
//
//int Find(int temp_numer, int temp_denom,  int index)
//{
//	if (index > memoi[temp_denom].size())
//		return 0;
//
//	for (int i = index; i < memoi[temp_denom].size(); i++)
//	{
//		if (temp_numer - memoi[temp_denom][i] > 0)
//		{
//			if (Find(temp_numer - memoi[temp_denom][i], temp_denom, i + 1))
//			{
//				if (index == 0)
//					return temp_denom / memoi[temp_denom][i];
//
//				else
//					return 1;
//			}
//		}
//
//		else if (temp_numer - memoi[temp_denom][i] == 0)
//		{
//			return 1;
//		}
//
//		else if (temp_numer - memoi[temp_denom][i] < 0)
//			return 0;
//
//	}
//
//
//
//}
//
//int FindHenry(int denom, int numer)
//{
//	int temp_denom = denom;
//	int temp_numer = numer;
//	int ans = -1;
//
//	int max_multi = 10000 / denom;
//
//	for (int i = max_multi; i >= 1; i--)
//	{
//		temp_denom *= i;
//		temp_numer *= i;
//
//		SaveDivisor(temp_denom);
//		ans = Find(temp_numer, temp_denom, 0);
//
//
//		if (ans)
//			break;
//
//		else
//		{
//			temp_denom = denom;
//			temp_numer = numer;
//
//		}
//
//
//	}
//
//
//
//
//	return ans;
//
//
//
//
//
//}
