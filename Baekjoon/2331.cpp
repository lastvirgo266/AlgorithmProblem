#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> d;
	int digit = 1;
	int temp = 0;
	int number;
	int p;

	scanf("%d", &number);
	scanf("%d", &p);
	d.push_back(number);

	while (number/digit >= 10)
		digit *= 10;

	while (number != 0)
	{
		temp += pow((number / digit),p);
		number %= digit;
		digit /= 10;
	}

	vector<int>::iterator itr = find(d.begin(),d.end(),temp);
	while (itr == d.end())
	{
		d.push_back(temp);
		temp = 0;
		digit = 1;

		number = d[d.size() - 1];

		while (number/digit >= 10)
			digit *= 10;

		while (number != 0)
		{
			temp += pow((number / digit), p);
			number %= digit;
			digit /= 10;
		}
	itr = find(d.begin(), d.end(), temp);
	}
	printf("%d", d.size()-(d.end()-itr));

	return 0;
}