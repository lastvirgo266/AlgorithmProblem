#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
using namespace std;


int main()
{
	int n;
	scanf("%d", &n);
	vector<string> result;

	for (int i = 0; i < n; i++)
	{
		string thesis;
		cin >> thesis;

		int left = 0;
		int right = 0;
		int state = 0;


		for (int j = 0; j < thesis.length(); j++)
		{

			if (thesis[j] == '(')
			{
				left++;

			}


			else if (thesis[j] == ')')
			{
				right++;

			}

			if (left < right)
				break;


		}


		if ((left !=0) && (right !=0) && (left == right))
			result.push_back("YES");


		else
			result.push_back("NO");


	}


	for (int i = 0; i < result.size(); i++)
		cout << result[i]<<endl;



}