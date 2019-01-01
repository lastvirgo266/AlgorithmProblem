#include<stdio.h>
#include<vector>
using namespace std;


vector< vector<int> > memoi;
int N;


// 11057.cpp

int StageUp(int digit, int number)
{
	if (memoi[digit][number])
		return memoi[digit][number];

	if (digit == N)
		return 9 - number + 1;
	

	int ret = 0;

	for (int i = number; i <= 9; i++)
	{

		ret += StageUp(digit + 1, i) % 10007;
		ret %= 10007;


	}
	
	memoi[digit][number] = ret;





	return ret;



	


}




int main()
{
	memoi.resize(1000 + 1);

	for (int i = 1; i < memoi.size(); i++)
		memoi[i].resize(10);



	scanf("%d", &N);


	printf("%d", StageUp(1, 0));





}

