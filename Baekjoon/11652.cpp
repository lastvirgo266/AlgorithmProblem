#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int N;
	int now_count = -1;
	int max_count = -1;
	long long max_number = 0;
	long long prev_number;
	vector<long long> arr;

	//Input N
	scanf("%d", &N);

	//Input arr element
	for (int i = 0; i < N; i++) {
		long long temp;
		scanf("%lld", &temp);
		arr.push_back(temp);
	}

	//sort array
	sort(arr.begin(), arr.end());

	//Pre set
	now_count = 1;
	max_count = -1;
	prev_number = arr[0];
	max_number = arr[0];

	for (int i = 1; i < N; i++) {
		if (arr[i] == prev_number) //count same number
			now_count++;


		else {
			if (now_count > max_count) { //compare max count
				max_count = now_count; // replace max_count and max_number
				max_number = prev_number;
			}
			now_count = 1;
		}

		prev_number = arr[i]; // reset prev number
	}

	//Exception case (1)
	if (now_count > max_count) { //compare max count
		max_count = now_count; // replace max_count and max_number
		max_number = prev_number;
	}


	printf("%lld", max_number);
	return 0;


	

}