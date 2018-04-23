#include<iostream>
#include<vector>
#define ASCII 48
#define MAX 10
using namespace std;

inline void char_to_IntAdd(int *total, char *number){ *number == NULL ? *total : *total += ((int)*number - ASCII); }

void DigitCount(int *number)
{


}


int main(){
	char A[10000]{};
	char B[10000]{};
	int total[100000]{0};

	cin >> A;
	cin >> B;

	int i = 0;

	while (A[i] || B[i])
	{
		char_to_IntAdd(total+i, A+i);
		char_to_IntAdd(total+i, B+i);

		if (total[i] > MAX)
		{
			total[i] -= 10;
			total[i + 1] += 1;

			//TestLine
			//cout << total[i];
		}

		i++;
	}

	i--;

	int j = 0;

	while (j<=i)
	{
		cout << total[j++];
	}


	return 0;



}