#include<stdio.h>
#include<math.h>
#include<memory.h>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

// <size, digit>
vector<pair<int, int>> number_count;

// <size,digit>
vector<pair<int, int>> number_table;

int main(){


	char allNumber[50][50];

	int N;
	int digit_count = 0;

	//for set pair.second
	int weight;

	//Array set same value
	memset(*allNumber, NULL, sizeof(*allNumber));

	for (int i = 0; i < 36; i++){
		number_count.push_back(make_pair(0, i));
		number_table.push_back(make_pair(0, i));
	}


	//Input N's numebr
	scanf("%d", &N);

	//Input N
	for (int k = 0; k < N; k++)
		scanf("%s", allNumber[k]);


	for (int k = 0; k < N; k++){

		// Count digit
		for (int i = 0; allNumber[k][i] != NULL; i++)
			digit_count++;

		// Count Big digit and insert number_table
		for (int i = 0; i < digit_count; i++){

			// Count 0 to 9
			if ((int)allNumber[k][i] < 58)
				number_count[(int)allNumber[k][i] - 48].first = number_count[(int)allNumber[k][i] - 48].first + pow((double)36, (digit_count - i));

			

			else
				number_count[(int)allNumber[k][i] - 55].first = number_count[(int)allNumber[k][i] - 55].first + pow((double)36, (digit_count - i));

			




		}


		// Test Print //
		for (int i = 0; i < 36; i++){
			printf("%d   %d\n", number_count[i].first, number_count[i].second);
		}




		//count value set
		digit_count = 0;
	}

	//Before sort save number table
	number_table = number_count;


	//Sort
	sort(number_count.begin(), number_count.end());


	// Test Print //
	for (int i = 0; i < 36; i++){
		printf("%d   %d\n", number_count[i].first, number_count[i].second);
	}
	



	int K;

	//Input K
	scanf("%d", &K);

	//Making dynamic int array
	int *change_list;
	change_list = new int[K];

	//Input big digit to change_list
	for (int i = 0; i < K; i++)
		change_list[i] = number_count[35 - i].second;

		//Test Print //


	




	//Change
	for (int i = 0; i < K; i++)
		number_table[change_list[i]].second = 35;


	int result = 0;

	// PLUS
	for (int i = 0; i < 36; i++)
		result += number_table[i].first * number_table[i].second;


	printf("%d", result);




}


void plus_all_number(int change_count, int* change_list){

	//plus







}