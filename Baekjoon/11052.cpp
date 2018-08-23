#include<stdio.h>
#include<vector>
using namespace std;
#define MAX(a,b){a>b? a:b}


vector<int> cara;
vector<int> memoi;


int GetMax(int count)
{
	if (count == 0)
		return 0;

	else if (memoi[count])
		return memoi[count];

	int ret = 0;
	int max = -1;

	for (int i = 1; i <= count; i++)
	{

		ret = GetMax(count - i) + cara[i];

		max = MAX(ret, max);


	}

	memoi[count] = max;

	return max;


}

int main()
{
	int N;
	scanf("%d", &N);

	cara.resize(N+1);
	memoi.resize(N + 1);
	cara[0] = NULL;

	for (int i = 1; i <= N; i++)
	{
		int price;
		scanf("%d", &price);

		cara[i] = price;

	}


	printf("%d", GetMax(N));
	


	return 0;







}