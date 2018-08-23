#include<stdio.h>
#include<vector>
#define MAX(A,B)(A>B?A:B)
using namespace std;

//inline int MAX(int A, int B) { return A > B ? A : B; }

vector<int> memoi;


int Tile(int maxSequ)
{
	if (memoi[maxSequ])
		return memoi[maxSequ];

	int retThree = 0;
	int retTwo = 0;
	int retOne = 0;
	int result = -1;


	if (maxSequ == 0)
		return 1;


	if (maxSequ >= 2)
		retTwo = Tile(maxSequ - 2);

	if (maxSequ >= 2)
		retThree = Tile(maxSequ - 2);
	


	retOne = Tile(maxSequ - 1);

	result = retTwo + retOne + retThree;

	result %= 10007;

	memoi[maxSequ] = result;

	return result;



}


int main()
{
	memoi.resize(1000 + 1);
	int maxSequ;
	scanf("%d", &maxSequ);

	printf("%d", Tile(maxSequ));


	return 0;


}