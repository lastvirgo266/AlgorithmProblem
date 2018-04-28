#include<iostream>
#include<vector>
using namespace std;
int S;

inline int Check(int check){ return	( S == check ) ? 1 : 0; }


int GetSubset(vector<int> &number,int left, int right)
{

	// Base
	if (left >= right)
		return Check(number[right]);


	int total = 0;
	int temp = 0;
	int mid = (right + left) / 2 ;

	//Divide
	total += (GetSubset(number, left, mid) + GetSubset(number, mid + 1, right));

	// Compute Line
	int left_last = mid;
	int right_first = mid + 1;
	int left_complete = 0;
	int right_complete = 0;


	//TestLine
	cout << "---TEST----" << endl;
	cout << "left " << left << "    right : " << right << endl;


	//Connect left_last <--> right_first
	if (left_last >= left)
	{
		temp += number[left_last--];
	}


	if (right_first <= right)
	{
		temp += number[right_first++];
	}

	if (((left_last+1) >= left) && ((right_first-1) <= right))
		if (Check(temp))
			total += 1;

	int point_left = left_last;
	int point_right = right_first;

	// Search
	while ((left_last >= left) || (right_first<= right))
	{

		while ((point_left >= left) || (point_right <= right))
		{

			// search (бр)бсбс
			if (point_left >= left)
			{
				if (Check(temp + number[point_left--]))
					total += 1;
			}




			// search бсбс(бр)
			if (point_right <= right)
			{
				if (Check(temp + number[point_right++]))
					total += 1;
			}
		}//End of nested while




	}//End of while

	//TestLine
	cout << "Total Stack :" << total << endl;


	return total;



}



int main(void)
{
	
	int N;
	
	vector<int> number;
	int temp_number;

	cin >> N;
	cin >> S;

	for (int i = 0; i < N; i++)
	{
		cin >> temp_number;
		number.push_back(temp_number);
	}
	



	int val = GetSubset(number, 0, number.size() - 1);

	cout << val << '\n';


	return 0;




}