#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;


//Complete

int main()
{
	int pieces = 0;
	int i = 0;
	string ironBar;

	vector<char> stack;
	char handing = NULL;

	cin >> ironBar;



	while (ironBar.size() != i)
	{
		if (ironBar[i] == ')')
		{
			if (handing == '(')
			{
				pieces += stack.size();
				handing = NULL;
			}

			else if (handing == NULL)
			{
				pieces += 1;
				stack.pop_back();
			}

			else
				handing = ironBar[i];

		}


		else if (ironBar[i] == '(')
		{

			if (handing == '(')
			{
				stack.push_back(handing);
				handing = ironBar[i];
			}

			else
				handing = ironBar[i];

		}

		i++;




	}



	printf("%d", pieces);



	return 0;











}