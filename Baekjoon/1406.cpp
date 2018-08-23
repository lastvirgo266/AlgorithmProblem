#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string text;
	string temp;
	int N;
	cin >> text;
	scanf("%d", &N);



	
	for (int i = 0; i < N; i++)
	{
		string command;
		cin >> command;
		

		if (command[0] == 'L')
		{
			if (text.size() != 0)
			{
				temp.append(text.substr(text.size() - 1, 1));
				text.pop_back();
			}

		}


		else if (command[0] == 'D')
		{
			if (temp.size() != 0)
			{
				text.append(temp.substr(temp.size() - 1, 1));
				temp.pop_back();
			}
		}


		else if (command[0] == 'B')
		{
			if (text.size() != 0)
			{
				text.pop_back();
			}
		}


		else if (command[0] == 'P')
		{
			string add;
			cin >> add;
			text.append(add);

		}



	}

	reverse(temp.begin(), temp.end());
	text.append(temp);



	for (int i = 0; i < text.size(); i++)
		printf("%c", text[i]);

		

}