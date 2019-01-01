#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	vector< pair<int, int> > sorted;



	vector<int> a;
	int n;
	int start = 1;
	int end;

	int max_value = -1;
	int max_number = 0;

	scanf("%d", &n);
	a.resize(n + 1);
	sorted.resize(n + 1);
	end = n;

	//reset
	sorted[0].first = -1;
	sorted[0].second = -1;

	for (int j = 1; j < a.size(); j++)
	{
		int temp_value;
		scanf("%d", &temp_value);
		a[j] = temp_value;

		sorted[j].first = temp_value;
		sorted[j].second = j;
	}

	//Big(O) : log2n
	sort(sorted.begin(), sorted.end());


	//Big(O) : n
	//Find max distance
	for (int i = 1; i < sorted.size(); i++)
		if (sorted[i].second - i > max_value)
			max_value = abs(i - sorted[i].second);


	//Total Big(O) : log2n + n = n
	printf("%d\n", max_value + 1);


	return 0;


}