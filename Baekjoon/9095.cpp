#include<stdio.h>
#include<vector>
using namespace std;

vector<int> memoi;


int OneTwoThree(int n)
{
	int ret = 0;

	if (n == 0)
		return 1;

	else if (n < 0)
		return 0;

	if (memoi[n])
		return memoi[n];


	ret += OneTwoThree(n - 1);
	ret += OneTwoThree(n - 2);
	ret += OneTwoThree(n - 3);




	return ret;



}



int main()
{
	memoi.resize(11);



	int T;
	vector<int> result;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int N;
		scanf("%d", &N);

		int temp = OneTwoThree(N);
		memoi[N] = temp;

		result.push_back(temp);



	}

	
	for(int i=0; i<result.size(); i++)
		printf("%d\n", result[i]);



	
	return 0;


	






}