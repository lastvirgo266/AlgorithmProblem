#include<iostream>
#define ASCII 48
#define MAX 10
using namespace std;

inline void char_to_IntAdd(int *total, char *number){ *number == NULL ? *total : *total += ((int)*number - ASCII); }

int main(){
	char A[10001]{};
	char B[10001]{};

	int A_max_digit = -1;
	int B_max_digit = -1;
	int A_B_max_digit;

	int total[100000]{NULL};

	// Input Line //
	cin >> A;
	cin >> B;

	int i = 0;

	// Compute max Digit Line//
	while (A[i] || B[i])
	{
		if (A[i])
			A_max_digit++;
		
		if (B[i])
			B_max_digit++;

		i++;
	}

	A_B_max_digit = A_max_digit + B_max_digit + 2;


	// add total Line //
	i = 0;

	while ((A_max_digit>=0) || (B_max_digit>=0))
	{
		if (A_max_digit>=0)
			char_to_IntAdd(total+A_max_digit--, A+i);
		

		if (B_max_digit>=0)
			char_to_IntAdd(total+B_max_digit--, B+i);

		i++;

	}



	// Compute total's Digit Line //
	i = 0;

	while (i<=A_B_max_digit)
	{

		while (total[i] >= MAX)
		{
			total[i] -= MAX;
			total[i + 1] += 1;
		}

		i++;
	}


	// Printing Line //
	i--;
	
	bool print_start = false;

	while (i>=0)
	{
		if (total[i])
		{
			cout << total[i--];
			print_start = true;
		}

		else if (print_start == true)
			cout << total[i--];

		else
			i--;


		if ((i == 1) && (print_start == false))
		{
			print_start = true;
			i--;
		}


	}


	return 0;



}