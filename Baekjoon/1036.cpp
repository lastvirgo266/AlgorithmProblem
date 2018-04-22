#include<cmath>
#include<utility>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

void Digit_Count(vector<int> &total);
void Print_table(vector<int> &total);
void Total_Plus_Add(vector<int> &total, vector<int> &add, int coe);
void Number_Sort(vector<pair< vector<int>, int> > &number_count, vector<int> &change_list);




int main(){


	// <size, digit>
	vector<pair< vector<int>, int> > number_count;
	number_count.resize(36);

	// <size,digit>
	vector<pair< vector<int>, int> > number_table;
	number_table.resize(36);

	int number_length = 60;

	//finally change and save 36digit
	vector<int> change_list;
	vector<int> total;





	char allNumber[51][52];

	int N;
	int digit_count = 0;



	//Array set same value
	for (int i = 0; i < 51; i++)
		for (int j = 0; j < 52; j++)
			allNumber[i][j] = '-';

	for (int i = 0; i < number_count.size(); i++){
		number_count[i].first.resize(number_length);
		number_count[i].second = i;
	}


	for (int i = 0; i < number_table.size(); i++){
		number_table[i].first.resize(number_length);
		number_table[i].second = i;	

	}

	total.resize(number_length);



	//Input N's numebr
	cin >> N;


	//Input N

	for (int k = 0; k < N; k++)
		cin >> allNumber[k];
	//	scanf("%s", allNumber[k]);


	for (int k = 0; k < N; k++){



		// Count digit
		for (int i = 0; allNumber[k][i] != '-'; i++){
			//TestLine
			digit_count++;
		}

		digit_count--;



		bool start = false;
		// Count Big digit and insert number_table
		for (int i = 0; i < digit_count; i++){

			if (((int)allNumber[k][i] - 48) == 0);


			else
				start = true;


			if ((((int)allNumber[k][i] - 48) == 0) && (digit_count - i == 1))
				start = true;




			if (start == true){
				// Count 0 to 9
				if ((int)allNumber[k][i] < 58){
					number_count[(int)allNumber[k][i] - 48].first[digit_count - i] += (35 - (1 * number_count[(int)allNumber[k][i] - 48].second));
					number_table[(int)allNumber[k][i] - 48].first[digit_count - i] += 1;

				}



				else{
					number_count[(int)allNumber[k][i] - 55].first[digit_count - i] += (35 - (1 * number_count[(int)allNumber[k][i] - 55].second));
					number_table[(int)allNumber[k][i] - 55].first[digit_count - i] += 1;
				}
			}



		}


		//count value set
		digit_count = 0;
	}



	//Sort
	Number_Sort(number_count, change_list);


	//number_count deleted.


	int K;

	//Input K
	cin >> K;
	//scanf("%d", &K);

	if (N <= 0)
		return 0;


	//Change
	for (int i = 0; i < K; i++)
		number_table[change_list[i]].second = 35;



	//total += number_table

	for (int i = 0; i < number_table.size(); i++)
		Total_Plus_Add(total, number_table[i].first, number_table[i].second);



	//Print number
	Print_table(total);


	return 0;


}


void Digit_Count(vector<int> &total){
	int i = 1;

	while (i < total.size()){

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
	int i = 1;

	while ((i < total.size()) && (i < add.size())){
		total[i] += (add[i] * coe);
		i++;
	}

	Digit_Count(total);



}


void Print_table(vector<int> &total){

	bool start = false;

	for (int i = total.size() - 1; i >= 1; i--){


		if (total[i] >= 10){
			putchar((total[i] + 55));
			//cout << (char)(total[i] + 55);
			//printf("%c", (char)(total[i] + 55));
			start = true;
		}

		else if (total[i] == 0){
			if (start == false);
			//printf("");


			else
				putchar(total[i] + 48);
				//cout << "0";
			//printf("0");
		}

		else{
			putchar(total[i] + 48);
			//cout << (char)(total[i] + 48);
			//printf("%c", (char)(total[i] + 48));
			start = true;
		}

		if ((i == 1) && (total[i] == 0) && (start == false))
			putchar(total[i] + 48);
			//cout << "0";
		//printf("0");


	}
}


void Number_Sort(vector<pair< vector<int>, int> > &number_count, vector<int> &chage_list){

	for (int i = 0; i < number_count.size(); i++)
		Digit_Count(number_count[i].first);



	int count = number_count[0].first.size()-1;
	int delete_count = 0;
	int size = number_count.size();

	while ((count >= 1) && (size - delete_count != 0))
	{
		int max = 0;
		int max_count = -1;



		for (int i = 0; i < size; i++)
		{

			//if number_count[i].first[count] > max
			if (number_count[i].first[count] > max)
			{
				max = number_count[i].first[count];
				max_count = i;
			}


			//if number_count[i].first[count] == max
			else if ((number_count[i].first[count] == max) && (number_count[i].first[count] != 0))
			{
				int j = count;

				while (j >= 1)
				{
					if (number_count[i].first[j] >= number_count[max_count].first[j]){
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
			//number_count.erase(number_count.begin() + max_count);
			
			for (int i = 0; i < number_count[max_count].first.size(); i++)
				number_count[max_count].first[i] = 0;
			//delete_count++;
		}




	}


	
	//Handle remainder

	vector<pair< vector<int>, int> >::iterator count_itr;
	for (count_itr = number_count.begin(); count_itr != number_count.end(); count_itr++)
		chage_list.push_back((*count_itr).second);


	number_count.clear();


}