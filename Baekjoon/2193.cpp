#include<iostream>
using namespace std;
inline int ReverseNumber(int pinary){ return pinary == 1 ? 0 : 1; }
long long memoi[2][90]{}; //Using memoization


long long Pinary(long long number, int count)
{
	if (count == 1)
		return 1;

	// Case number == 1
	if (number)
	{
		if (memoi[0][count - 1])
			return memoi[ReverseNumber(number)][count - 1];

		else
			return memoi[ReverseNumber(number)][count - 1] = Pinary(ReverseNumber(number), count - 1);
	}


	// Case number == 0
	else
	{
		if (memoi[1][count - 1] || memoi[0][count - 1])
			return memoi[1][count - 1] + memoi[0][count - 1];

		else
		{
			memoi[0][count - 1] = Pinary(0, count - 1);
			memoi[1][count - 1] = Pinary(ReverseNumber(number), count - 1);
			return memoi[0][count - 1] + memoi[1][count - 1];
		}
	}

}


int main(void)
{
	int N;


	//Input Line//
	cin >> N;

	// Compute Line //
	long long number = Pinary(1, N);

	// Print Line //
	cout << number;

	return 0;


}