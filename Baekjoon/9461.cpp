#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;




int main()
{
	int T;
	vector<long long> d(100 + 1);
	scanf("%d", &T);

	vector<long long> res(T);
	vector<int> N(T);

	for (int i = 0; i < T; i++)
	{
		cin >> N[i];
	}


	for (int t = 0; t < N.size(); t++)
	{
		int n = N[t];

		d[1] = 1;
		d[2] = 1;
		d[3] = 1;
		d[4] = 2;
		d[5] = 2;
		d[6] = 3;

		if (n >= 7)
			for (int i = 7; i <= n; i++)
			{

				d[i] = d[i - 1] + d[i - 5];

			}

		res[t] = d[n];

	}


	for(int i=0; i<res.size(); i++)
		printf("%lld\n", res[i]);

	

	return 0;



}