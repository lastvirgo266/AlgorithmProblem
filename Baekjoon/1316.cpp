#include<iostream>
#include<string>
#define ASCII 128
using namespace std;


int GetGroupWord(string group)
{
	bool appear_word[ASCII] = { 0, };
	char now_appear = NULL;
	int i = 0;

	while (i <= (group.size()-1))
	{
		if (now_appear != group[i])
		{
			now_appear = group[i];
			if (appear_word[(int)now_appear])
				return 0;
		}

		appear_word[(int)now_appear] = 1;
		i++;

	}

	return 1;


}
int main()
{
	

	int N;
	int count = 0;

	cin >> N;


	while (N >= 1)
	{
		string group;
		cin >> group;

		count += GetGroupWord(group);

		N--;
	}


	cout << count << endl;

	
	
	







}