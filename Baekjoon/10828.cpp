#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

vector<int> result;



int main()
{
	int n;
	vector<int> stack;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		string command;
		cin >> command;


		if (command.compare("push") == 0)
		{

			char blank;
			scanf("%c", &blank);

			int inputNumber;
			scanf("%d", &inputNumber);
			stack.push_back(inputNumber);
		}


		else if (command.compare("pop") == 0)
		{

			if (stack.size() == 0)
				result.push_back(-1);

			else
			{
				result.push_back(stack[stack.size() - 1]);
				stack.pop_back();
			}

		}


		else if (command.compare("size") == 0)
			result.push_back(stack.size());


		else if (command.compare("empty") == 0)
		{ 
			if (stack.empty())
				result.push_back(1);

			else
				result.push_back(0);

		}


		else if (command.compare("top") == 0)
		{
			if (stack.size() == 0)
				result.push_back(-1);

			else
				result.push_back(stack[stack.size() - 1]);
			
		}



	}



	for (int i = 0; i < result.size(); i++)
		printf("%d\n", result[i]);


	return 0;



}

