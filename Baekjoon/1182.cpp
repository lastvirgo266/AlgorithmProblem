#include<iostream>
#include<vector>
using namespace std;
int S;
vector<int> number;

inline int Check(int check){ return	( S == check ) ? 1 : 0; }

int GetSubset(int temp, int index)
{

	//Base 1 for time shrot
	if (index == (number.size() - 1))
		return Check(temp + number[index]);

	//Base 2
	else if (index > (number.size() - 1))
		return 0;

	int total = 0;

	for (int i = index; i <= (number.size()-1); i++)
	{
		// Search now level like this
		//   (бр)
		// бс(бр) .....
		//   (бр)
		if (Check(temp + number[i]))
			total += 1;

		// Search next level like this
		//    (бр)
		//  бс бр
		//бсбр бр .......
		//  бр бр
		//     бр

		//     бр
		//  бс(бр)
		//бсбр бр .......
		//  бр бр
		//     бр
		for (int j = i+1; j <= (number.size() - 1); j++)
		{
			//Check temp + now_node + child_node
			if (Check(temp + number[i] + number[j]))
				total += 1;

			// Call child_child_node
			total += GetSubset(temp + number[i] + number[j], j+1);
		}



	}// End of for


	return total;


}



int main(void)
{
	
	int N;
	int temp_number;

	cin >> N;
	cin >> S;

	for (int i = 0; i < N; i++)
	{
		cin >> temp_number;
		number.push_back(temp_number);
	}
	
	int val = GetSubset(0, 0);

	cout << val << '\n';


	return 0;




}