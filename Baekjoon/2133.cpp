#include<stdio.h>
#include<vector>
using namespace std;


int main()
{

	vector<long long> d(30 + 1);
	int N;

	scanf("%d", &N);
	
	
	for (int i = 0; i < d.size(); i++)
		d[i] = 0;

	d[0] = 1;



	d[0] = 1;
	d[2] = 3;

	for (int i = 4; i <= N; i += 2) 
	{
		d[i] = 3 * d[i - 2];


		for (int j = 4; j <= i; j += 2) 
		{
			d[i] += 2 * d[i - j];
		}


	}


/*
	for (int i = 0; i <= N; i++)
	{
		
		if (d[i] != 0)
		{
			
			if( i+2<= N)
				d[i + 2] += d[i]*3;
			
			for(int j=4; j<=i; j+=2)
				for(int k=j; k+i<=N; k+=k)
					if(i+k <= N)
						d[i + k] += d[i]*2;


		}



		
	}*/




	printf("%lld", d[N]);


	return 0;


}