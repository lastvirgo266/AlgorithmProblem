#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() 
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<long long> d(n);

	for (int i = 0; i<n; i++) 
	{
		cin >> a[i];
	}


	d[0] = (long long)a[0];

	for (int i = 1; i<n; i++) 
	{
		d[i] = (long long)a[i];
		int j = i - 1;

			if (d[j] + (long long)a[i] > d[i])
			{
				d[i] = d[j] + (long long)a[i];
			}
		
	}

	cout << *max_element(d.begin(), d.end()) << '\n';
	return 0;
}
