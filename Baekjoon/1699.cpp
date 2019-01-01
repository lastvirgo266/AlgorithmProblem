#include<stdio.h>
#include<math.h>
using namespace std;


int main()
{
	int d[100000+1];
	d[0] = 0;


	int n;
	scanf("%d", &n);

	


	for (int i = 1; i <= n; i++)
	{
		d[i] = i;

		for (int j = 0; j <= (int)sqrt(i)+1; j++)
		{
			if (i >= j*j)
				if(d[i] > d[i - j*j] + 1)
					d[i] = d[i - j*j] + 1;
		}

	}


	printf("%d", d[n]);



	return 0;
}