#include<stdio.h>
#include<math.h>
#include<memory.h>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

void Digit_Count(vector<int> &total);
void Print_table(vector<int> &total);
void Total_Plus_Add(vector<int> &total, vector<int> &add, int coe);
void Number_Sort(vector<pair<vector<int>, int>> &number_count, vector<int> &change_list);




int main(){



	// <size, digit>
	vector<pair<vector<int>, int>> number_count;
	number_count.resize(36);

	// <size,digit>
	vector<pair<vector<int>, int>> number_table;
	number_table.resize(52);


	//finally change and save 36digit
	vector<int> change_list;
	vector<int> total;




	char allNumber[51][51];

	int N;
	int digit_count = 0;


	//Array set same value
	memset(*allNumber, NULL, sizeof(*allNumber));

	for (int i = 0; i < number_count.size(); i++){
		number_count[i].second = i;

		for (int j = 0; j <= 51; j++)
			number_count[i].first.push_back(0);
	}

	for (int i = 0; i <= 51; i++){
		total.push_back(0);
		number_table[i].second = i;

		
		for (int j = 0; j <= 51; j++)
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
				number_count[(int)allNumber[k][i] - 48].first[digit_count - i] += (35 - (1 * number_count[(int)allNumber[k][i] - 48].second));
				number_table[(int)allNumber[k][i] - 48].first[digit_count - i] +=1;



			}

			

			else{
				number_count[(int)allNumber[k][i] - 55].first[digit_count - i] += (35 - (1 * number_count[(int)allNumber[k][i] - 55].second));
				number_table[(int)allNumber[k][i] - 55].first[digit_count - i] += 1;
			}

			




		}


		//count value set
		digit_count = 0;
	}


	//Sort
	Number_Sort(number_count, change_list);
	

	int K;

	//Input K
	scanf("%d", &K);


	//Change
	for (int i = 0; i < K; i++)
		number_table[change_list[i]].second = 35;


	//total += number_table

	for (int i = 0; i <= 51; i++)
		Total_Plus_Add(total, number_table[i].first, number_table[i].second);


	//Print space
	Print_table(total);
	



}



void Digit_Count(vector<int> &total){
	int i = 0;

	while (i < 51){

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


void Number_Sort(vector<pair<vector<int>, int>> &number_count, vector<int> &chage_list){
	
	for (int i = 0; i < 36; i++)
		Digit_Count(number_count[i].first);
	



	int count = 51;
	int delete_count = 0;

	while (count >= 1){
		int max = 0;
		int max_count = 0;



		for (int i = 0; i < 36-delete_count; i++){

			//if number_count[i].first[count] > max
			if (number_count[i].first[count] > max){
				max = number_count[i].first[count];
				max_count = i;
			}


			//if number_count[i].first[count] == max
			else if ((number_count[i].first[count] == max) && ( number_count[i].first[count] != 0)){
				int j = count;

				while (j >= 0){
					if (number_count[i].first[j] > number_count[max_count].first[j]){
						max_count = i;
						break;
					}

					else
						j--;

				}

			}
		//End of elif


		}

		if (max == 0)
			count--;


		else{
			//비교가 끝난 요소 삭제!
			chage_list.push_back(number_count[max_count].second);
			number_count.erase(number_count.begin() + max_count);
			delete_count++;
		}




	}


	//Handle remainder
	vector<pair<vector<int>, int>>::iterator count_itr;

	for (count_itr = number_count.begin(); count_itr != number_count.end(); count_itr++)
		chage_list.push_back((*count_itr).second);





}