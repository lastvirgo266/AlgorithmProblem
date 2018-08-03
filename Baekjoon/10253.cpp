#include<stdio.h>
#include<iostream>
#include<time.h>
#include<vector>
#include<map>
using namespace std;

vector< vector<short> > memoi;

void SaveDivisor(int temp_denom)
{


	int count = 0;
	vector<short> div;

	if (memoi[temp_denom].size())
		return;



	for (int i = 1; i <= 10000; i++)
	{



		


		/* 굳이 필요없는 라인
		if (memoi[i].size())
		{
			for (int j = 0; j < memoi[i].size(); i++)
				div.push_back(memoi[i][j]);

		}*/

		if (temp_denom % i == 0)
		{
			div.push_back(i);
		}





	}


	memoi[temp_denom] = div;



}

int Find(int temp_numer, int temp_denom,  int index)
{
	if (index > memoi[temp_denom].size())
		return 0;

	for (int i = index; i < memoi[temp_denom].size(); i++)
	{
		if (temp_numer - memoi[temp_denom][i] > 0)
		{
			if (Find(temp_numer - memoi[temp_denom][i], temp_denom, i + 1))
			{
				if (index == 0)
					return temp_denom / memoi[temp_denom][i];

				else
					return 1;
			}
		}

		else if (temp_numer - memoi[temp_denom][i] == 0)
		{
			return 1;
		}

		else if (temp_numer - memoi[temp_denom][i] < 0)
			return 0;

	}



}

int FindHenry(int denom, int numer)
{
	int temp_denom = denom;
	int temp_numer = numer;
	int ans = -1;

	int max_multi = 10000 / denom;

	for (int i = max_multi; i >= 1; i--)
	{
		temp_denom *= i;
		temp_numer *= i;

		SaveDivisor(temp_denom);
		ans = Find(temp_numer, temp_denom, 0);


		if (ans)
			break;

		else
		{
			temp_denom = denom;
			temp_numer = numer;

		}


	}




	return ans;





}





int main()
{
	memoi.resize(10001);


	clock_t begin, end;
	begin = clock();        // 시간설정

	/************************************************************************/

	int test_case;
	scanf("%d", &test_case);

	vector<short> numer;
	vector<short> denom;
	numer.resize(test_case);
	denom.resize(test_case);

	for (int i = 0; i < test_case; i++)
	{
		int tNumer;
		int tDenom;

		scanf("%d", &tNumer);
		scanf("%d", &tDenom);

		numer[i] = tNumer;
		denom[i] = tDenom;


	}

	for (int i = 0; i < test_case; i++)
	{

		printf("%d\n", FindHenry(denom[i], numer[i]));
	}





	/************************************************************************/


	end = clock();          // 시간설정
	cout << "수행시간 : " << ((end - begin) / CLOCKS_PER_SEC) << endl;






	return 0;

}





