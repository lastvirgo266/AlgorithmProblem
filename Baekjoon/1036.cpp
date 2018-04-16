#include<stdio.h>
#include<math.h>
#include<memory.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
void Digit_Count(vector<int> &total);
//void Add_36digit(vector<int> &total, unsigned long long add_number);
void Print_table(vector<int> &total);
void Total_Plus_Add(vector<int> &total, vector<int> &add, int coe);




int main(){


	// <size, digit>
	vector<pair<unsigned long long, int>> number_count;

	// <size,digit>
	vector<pair<vector<int>, int>> number_table;
	number_table.resize(52);


	//finally change and save 36digit
	vector<int> total;



	char allNumber[50][50];

	int N;
	int digit_count = 0;


	//Array set same value
	memset(*allNumber, NULL, sizeof(*allNumber));

	for (int i = 0; i < 36; i++){
		number_count.push_back(make_pair(0, i));

	}

	for (int i = 0; i <= 51; i++){
		total.push_back(0);
		number_table[i].second = i;




		
		for (int i = 0; i <= 51; i++)
			number_table[i].first.push_back(0);

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
			if ((int)allNumber[k][i] < 58){
				number_count[(int)allNumber[k][i] - 48].first = number_count[(int)allNumber[k][i] - 48].first + pow((double)2, (digit_count - i));
			//	Add_36digit(number_table[(int)allNumber[k][i] - 48].first, pow((double)36, (digit_count - i)));
				number_table[(int)allNumber[k][i] - 48].first[digit_count - i] +=1;



			}

			

			else{
				number_count[(int)allNumber[k][i] - 55].first = number_count[(int)allNumber[k][i] - 55].first + pow((double)2, (digit_count - i));
				//Add_36digit(number_table[(int)allNumber[k][i] - 55].first, pow((double)36, (digit_count - i)));
				number_table[(int)allNumber[k][i] - 55].first[digit_count - i] += 1;
			}

			




		}






		//count value set
		digit_count = 0;
	}


	//Need modify

	//Before sorting, save number table
	//number_table = number_count;




	//Sort

		//For weight
	for (int i = 0; i < 36; i++)
		number_count[i].first = number_count[i].first ;

	sort(number_count.begin(), number_count.end());

	//TestLine

	for (int i = 0; i < 36; i++)
		cout << number_count[i].first <<"   "<<number_count[i].second << endl;
	



	int K;

	//Input K
	scanf("%d", &K);

	//Making dynamic int array
	int *change_list;
	change_list = new int[K];

	//Input big digit to change_list
	for (int i = 0; i < K; i++)
		change_list[i] = number_count[35 - i].second;


	




	//Change
	for (int i = 0; i < K; i++)
		number_table[change_list[i]].second = 35;



	// Need modify

	// PLUS
//	for (int i = 0; i < 36; i++)
//		Add_36digit( number_table[i].first * (unsigned long long)number_table[i].second);

	// Need modify



	//total += number_table

	for (int i = 0; i <= 51; i++)
		Total_Plus_Add(total, number_table[i].first, number_table[i].second);


	//Print space
	Print_table(total);
	



}


/*
void Add_36digit(vector<int> &total, unsigned long long add_number){
	//plus
	int pow_number = 0;
	unsigned long long origin_number = add_number;
	unsigned long long temp_number = add_number;


	
	while (origin_number != 0){

		if (temp_number >= 36){
			temp_number /= 36;
			pow_number++;


			//TestLine
			printf("temp number : %d\n", temp_number);


		}
		else {


			total[pow_number] += temp_number;

			//TestLine
			printf("%d\n", total[pow_number]);

			//temp_number 예외처리
			if (temp_number == 0)
				temp_number = 1;

			//TestLine
			printf("origin number : %d\n");


			origin_number -= pow((double)36, pow_number)*temp_number;
			pow_number = 0;
			temp_number = origin_number;

		}

	}

	Digit_Count(total);

}

*/



void Digit_Count(vector<int> &total){
	int i = 0;

	while (i <= 51){

		if (total[i] >= 36){
			while (total[i] >= 36){
				total[i + 1] += 1;
				total[i] -= 36;
			}

			i++;
		}

		else{
			i++;
		}


	}



}


void Total_Plus_Add(vector<int> &total, vector<int> &add, int coe){
	int i = 0;

	while (i <= 51){
		total[i] += add[i]*coe;
		i++;
	}

	Digit_Count(total);


}


void Print_table(vector<int> &total){

	bool start = false;

	for (int i = 51; i >= 1; i--){


		if (total[i] >= 10){
			printf("%c", (char)(total[i] + 55));
			start = true;
		}

		else if (total[i] == 0){
			if (start == false)
				printf("");

			else
				printf("0");
		}

		else{
			printf("%c", (char)(total[i] + 48));
			start = true;
		}

	}
}