#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>


int main(){
	int number_count[37];

	char tNumber[50] = { NULL };
	int count = 0;

	//Array set same value
	memset(tNumber, NULL, sizeof(tNumber));
	memset(number_count, 0, sizeof(number_count));

	scanf("%s", tNumber);


	for (int i = 0; tNumber[i] != NULL; i++)
		count++;



	for (int i = 0; i < count; i++){

		// Count 0 to 9
		if ((int)tNumber[i] < 58)
			number_count[(int)tNumber[i] - 48] = pow((double)35, (count - i));

		else
			number_count[(int)tNumber[i] - 55] = pow((double)35, (count - i));
	}


	//count value set
	count = 0;












}


void Sort_alphabet(int change_count, char* tNumber){



}