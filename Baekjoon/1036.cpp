#include<stdio.h>
#include<math.h>
#include<memory.h>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

// <size, digit>
vector<pair<int, int>> number_count;

int main(){


	char allNumber[50][50];

	int N;
	int digit_count = 0;

	//Array set same value
	memset(*allNumber, NULL, sizeof(*allNumber));

	for (int i = 0; i < 36; i++)
		number_count.push_back(make_pair(0, i));



	scanf("%d", &N);

	for (int k = 0; k < N; k++)
		scanf("%s", allNumber[k]);


	for (int k = 0; k < N; k++){

		// Count digit
		for (int i = 0; allNumber[k][i] != NULL; i++)
			digit_count++;
		

		// Count Big digit
		for (int i = 0; i < digit_count; i++){

			// Count 0 to 9
			if ((int)allNumber[k][i] < 58)
				number_count[(int)allNumber[k][i] - 48].first = number_count[(int)allNumber[k][i] - 48].first + pow((double)35, (digit_count - i));

			else
				number_count[(int)allNumber[k][i] - 55].first = number_count[(int)allNumber[k][i] - 55].first + pow((double)35, (digit_count - i));
		}


		// Test Print //
		for (int i = 0; i < 36; i++){
			printf("%d   %d\n", number_count[i].first, number_count[i].second);
		}




		//count value set
		digit_count = 0;
	}

	sort(number_count.begin(), number_count.end());


	// Test Print //
	for (int i = 0; i < 36; i++){
		printf("%d   %d\n", number_count[i].first, number_count[i].second);
	}
	


	int K;

	scanf("%d", &K);

	int change_list[5];


	for (int i = 0; i < K; i++)
		change_list[i] = number_count[35 - i].second;

		//Test Print //






}


void Sort_Cahnge_alphabet(int change_count, char* allNumber){

	//Sorting







}