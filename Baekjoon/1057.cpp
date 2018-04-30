#include<iostream>
#include<vector>
using namespace std;
inline int Check(int check){ return (check == 2) ? 1 : 0; }

int RoundCompting(vector<int>now, int now_round)
{

	if (now.size() == 2)
	{
		if (Check(now[1]))
			return now_round;
		else
			return -1;
	}

	
	vector<int> next;
	next.push_back(-1);

	for (int i = 1; i <= now.size() - 1; i += 2)
	{
		
		if (now.size() - 1 < (i+1))
			next.push_back(now[i]);

		else
			next.push_back(now[i] + now[i+1]);



		if (Check(next[(i + 1) / 2]))
			return now_round;
		
	}


	return RoundCompting(next, now_round + 1);




}



int main(void)
{
	vector<int> now;
	now.push_back(-1);

	int N;
	int J;
	int I;

	cin >> N;
	cin >> J;
	cin >> I;

	for (int i = 0; i < N; i++)
		now.push_back(0);

	now[I] = 1;
	now[J] = 1;

	int val = RoundCompting(now, 1);

	cout << val << '\n';


}