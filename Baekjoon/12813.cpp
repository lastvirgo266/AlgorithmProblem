#include<iostream>
#define ASCII 48
#define MAX 2
using namespace std;

inline void char_to_IntAdd(int *total, char *number){ *number == NULL ? *total : *total += ((int)*number - ASCII); }
inline int And(int A, int B){ return A * B; }
inline int Or(int A, int B){ return (A + B) == 2 ? 1 : A + B; }
inline int Xor(int A, int B){ return (A == B) ? 0 : 1; }
inline int Reverse(int A){ return A == 1 ? 0 : 1; }

int main(){
	char A[100001]{};
	char B[100001]{};

	int A_max_digit = -1;
	int B_max_digit = -1;
	int A_B_max_digit;

	int A_int[100001]{NULL};
	int B_int[100001]{NULL};

	// Input Line //
	cin >> A;
	cin >> B;

	int i = 0;

	// Compute Max Digit Line//
	while (A[i] || B[i])
	{
		if (A[i])
			A_max_digit++;

		if (B[i])
			B_max_digit++;

		i++;
	}

	A_B_max_digit = A_max_digit > B_max_digit ? A_max_digit: B_max_digit;


	// char to int Line //
	i = 0;

	while ((A_max_digit >= 0) || (B_max_digit >= 0))
	{
		if (A_max_digit >= 0)
			char_to_IntAdd(A_int + A_max_digit--, A + i);


		if (B_max_digit >= 0)
			char_to_IntAdd(B_int + B_max_digit--, B + i);

		i++;

	}


	// Printing Line //
	i--;

	int count = i;

		// Pirnt And //
	while (count >= 0)
	{
		cout << And(A_int[count], B_int[count]);
		count--;
	}

	cout << endl;
	count = i;


		// Print Or //
	while (count >= 0)
	{
		cout << Or(A_int[count], B_int[count]);
		count--;
	}



	cout << endl;
	count = i;


		// Print Xor //
	while (count >= 0)
	{
		cout << Xor(A_int[count], B_int[count]);
		count--;
	}


	cout << endl;
	count = i;


		// Print A Reverse //
	while (count >= 0)
	{
		cout << Reverse(A_int[count]);
		count--;
	}


	cout << endl;
	count = i;


		// Print B Reverse //
	while (count >= 0)
	{
		cout << Reverse(B_int[count]);
		count--;
	}


	return 0;



}