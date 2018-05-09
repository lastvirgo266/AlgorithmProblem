#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#define X 0
#define Y 1
#define INF 400000000


using namespace std;

inline int GetRealDistance(vector<short> point_1, vector<short> point_2){ return pow(point_1[X] - point_2[X], 2) + pow(point_1[Y] - point_2[Y], 2);}
inline int GetMin(int min, int temp){ return min <= temp ? min : temp; }


int main(void)
{

	vector< pair<int, vector<short> > > number;

	int n;
	cin >> n;
	number.resize(n);

	for (int i = 0; i < n; i++)
	{
		short a, b;
		cin >> a;
		cin >> b;

		number[i].second.resize(2);
		number[i].second[X] = a;
		number[i].second[Y] = b;
		number[i].first = (pow(a, 2) + pow(b, 2)); //Calculate relative distance to point (0,0)
	}


	//sort
	sort(number.begin(), number.end());



	int i = 0;
	int min = INF;


	if (number.size() <= 3)
	{
		if (number.size() == 2)
		{
			min = GetMin(min, GetRealDistance(number[i].second, number[i + 1].second));
		}

		else if (number.size() == 3)
		{
			min = GetMin(min, GetRealDistance(number[i].second, number[i + 1].second));
			min = GetMin(min, GetRealDistance(number[i].second, number[i + 2].second));
			min = GetMin(min, GetRealDistance(number[i+1].second, number[i + 2].second));
		}
	}


	else
	{
		while (i < number.size() - 3)
		{
			//Think, the number of quadrant is 4
			min = GetMin(min, GetRealDistance(number[i].second, number[i + 1].second));
			min = GetMin(min, GetRealDistance(number[i].second, number[i + 2].second));
			min = GetMin(min, GetRealDistance(number[i].second, number[i + 3].second));

			cout << min << endl;


			if (i+1 >= number.size() - 3)
			{
				//When the number is last.
				min = GetMin(min, GetRealDistance(number[i+1].second, number[i + 2].second));
				min = GetMin(min, GetRealDistance(number[i+1].second, number[i + 3].second));
				min = GetMin(min, GetRealDistance(number[i+2].second, number[i + 3].second));

			}
			
			i++;




		}
	}

	cout << min << endl;

}