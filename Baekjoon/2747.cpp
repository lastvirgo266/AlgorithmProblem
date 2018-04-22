#include<iostream>
#include<vector>
using namespace std;

int Fibonacci(int n, vector<int> &memoi)
{
	if (memoi[n] != 0)
		return memoi[n];
	
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	int number = Fibonacci(n - 1, memoi) + Fibonacci(n - 2, memoi);
	memoi[n] = number;

	return number;
}



int main()
{
	int n;
	vector<int> memoi;
	memoi.resize(46);

	cin >> n;

	n = Fibonacci(n,memoi);

	cout << n;


	return 0;

}