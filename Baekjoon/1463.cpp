#include<stdio.h>
#include<vector>
//#define MIN(A,B){A<B ? A:B}
#define MAX 1000001

inline int MIN(int A, int B) { return A < B ? A : B; }

using namespace std;

vector<int> memoi;



int MadeOne(int number)
{
	//Base
	if (number == 1)
		return 0;

	if (memoi[number])
		return memoi[number];


	int min = MAX;
	int ret = MAX;

	if (number % 2 == 0)
	{
		ret = MadeOne(number / 2)+1;
		min = MIN(min, ret);
	}


	if (number % 3 == 0)
	{
		ret = MadeOne(number / 3)+1;
		min = MIN(min, ret);
	}


	ret = MadeOne(number - 1)+1;
	min = MIN(min, ret);



	memoi[number] = min;



	return min;



}



int main()
{
	memoi.resize(1000000 + 1);

	int number;
	scanf("%d", &number);


	printf("%d", MadeOne(number));


	return 0;


}

