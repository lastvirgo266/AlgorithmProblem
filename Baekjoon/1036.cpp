#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>


int number_count[37];

int main(){


	char tNumber[50] = { NULL };
	char allNumber[50][50];

	int N;
	int digit_count = 0;

	//Array set same value
	memset(tNumber, NULL, sizeof(tNumber));
	memset(number_count, 0, sizeof(number_count));
	memset(*allNumber, NULL, sizeof(*allNumber));



	scanf("%d", &N);
	scanf("%s", tNumber);


	for (int k = 0; k < N; k++){


		for (int i = 0; tNumber[i] != NULL; i++){
			digit_count++;
			allNumber[k][i] = tNumber[i];
		}



		for (int i = 0; i < digit_count; i++){

			// Count 0 to 9
			if ((int)tNumber[i] < 58)
				number_count[(int)tNumber[i] - 48] = pow((double)35, (digit_count - i));

			else
				number_count[(int)tNumber[i] - 55] = pow((double)35, (digit_count - i));
		}




		//count value set
		digit_count = 0;
	}


	int K;

	scanf("%d", &K);






}


void Sort_Cahnge_alphabet(int change_count, char* allNumber){

	//Sorting







}