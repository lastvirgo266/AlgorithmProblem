#include<iostream>
using namespace std;

int BinaryChange(long long A)
{
	short number;

	//Base
	if (A <= 1)
	{
		cout << A;
		return 0;
	}


	if (A % 2 == 1)
		number = 1;

	else
		number = 0;

	BinaryChange(A / 2);

	cout << number;


}


int main(){
	long long A;


	// Input Line //
	cin >> A;


	// Compute max and Printing Line//

	BinaryChange(A);




	return 0;



}