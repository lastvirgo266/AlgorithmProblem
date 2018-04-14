#include<stdio.h>
#include<math.h>
#include<memory.h>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;
void Digit_Count();
void Add_36digit(int);


// <size, digit>
vector<pair<int, int>> number_count;

// <size,digit>
vector<pair<int, int>> number_table;


// change and save 36digit
vector<int> number_table_change;

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

	for (int i = 0; i <= 50; i++)
		number_table_change.push_back(0);


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

	//Before sorting, save number table
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
		Add_36digit( number_table[i].first * number_table[i].second);


	printf("%d", result);


	//TestLine
	printf("\n-----------------------------------------------------------\n");
	bool start = false;

	for (int i = 50; i >= 0; i--){


		if (number_table_change[i] >= 10){
			printf("%c", (char)(number_table_change[i] + 55));
			start = true;
		}

		else if (number_table_change[i] == 0){
			if (start == false)
				printf("");

			else
				printf("0");
		}

		else{
			printf("%c", (char)(number_table_change[i] + 48));
			start = true;
		}

	}


	for (int i = 50; i >= 0; i--)
		printf("원본값 : %d\n", number_table_change[i]);


}


void Add_36digit(int add_number){
	//plus
	int pow_number = 0;
	int origin_number = add_number;
	int temp_number = add_number;

	//TestLine
	printf("%d\n", add_number);
	
	while (origin_number != 0){

		if (temp_number > 36){
			temp_number /= 36;
			pow_number++;
			printf("pow_number : %d\n", pow_number);
		}

		else {


			number_table_change[pow_number] += temp_number;

			//temp_number 예외처리
			if (temp_number == 0)
				temp_number = 1;

			origin_number -= pow((double)36, pow_number)*temp_number;
			pow_number = 0;
			temp_number = origin_number;
			Digit_Count();
			printf("저장완료\n");
			printf("add_number : %d\n", origin_number);
		}

	}



}



void Digit_Count(){
	int i = 0;

	while (i <= 50){
		if (number_table_change[i] >= 36){
			number_table_change[i + 1] += 1;
			number_table_change[i] -= 36;
			i++;
		}

		else{
			i++;
		}


	}



}