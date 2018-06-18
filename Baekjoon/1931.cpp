#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

using namespace std;
inline int Max(int a, int b) { return a > b ? a : b; }


map<int, set<int> > meeting_time;
vector<int> first_time;
map< int, int > dp;


int bSearch(int lastTime, int first, int last)
{
	if (first > last) return -1;

	int mid = (first + last) / 2;

	if (mid == 0)
	{
		if (first_time[mid] >= lastTime)
			return mid;
	}


	else if (lastTime <= first_time[mid] && lastTime >= first_time[mid - 1])
	{

		if (lastTime == first_time[mid - 1])
			return mid - 1;

		return mid;
	}

	else if (lastTime < first_time[mid])
		return bSearch(lastTime, first, mid - 1);

	else
		return bSearch(lastTime, mid + 1, last);
}


int MaxMeeting(int lastTime, int stack)
{

	int max = -1;

	if (lastTime > (--meeting_time.end())->first)
	{
		return stack;
	}

	else if (dp.find(lastTime) != dp.end())
	{
		return dp.find(lastTime)->second + stack;
	}

	//Start Code
	else if (stack == 0)
	{
		for (int i=0; i<first_time.size(); i++)
		{
			for (set<int>::iterator set_itr = meeting_time[first_time[i]].begin(); set_itr != meeting_time[first_time[i]].end(); set_itr++) {
				max = Max(MaxMeeting(*set_itr, stack + 1), max);
			}

		}

		return max;
	}


	else
	{
		//Push Code
		int firstIndex = 0;
		int lastIndex = (first_time.size() - 1);
		int index = -1;
		int nextTime = -1;

		index = bSearch(lastTime, firstIndex, lastIndex);

		if (index != -1)
		{

			if (first_time[index] != (--meeting_time.end())->first)
				nextTime = first_time[index + 1];

		}

		else
		{
			return stack;
		}



		for (set<int>::iterator set_itr = meeting_time[first_time[index]].begin(); set_itr != meeting_time[first_time[index]].end(); set_itr++)
		{
			//다음에 미팅시간보다 클 경우 패스 하는 경우의수도 생성시킴
			if (nextTime != -1)
			{
				if (*set_itr > nextTime)
				{
					max = Max(MaxMeeting(nextTime, stack), max);
				}

			}

			max = Max(MaxMeeting(*set_itr, stack + 1), max);

		}


		dp[lastTime] = max - stack;
		return max;


	}




}





int main()
{
	int N;
	scanf("%d", &N);


	int a, b = -1;

	for (int i = 0; i < N; i++)
	{

		scanf("%d", &a);
		scanf("%d", &b);

		meeting_time[a].insert(b);

	}

	for (map<int, set<int> >::iterator itr = meeting_time.begin(); itr != meeting_time.end(); itr++)
		first_time.push_back(itr->first);


	int max = 0;
	max = MaxMeeting(-1, 0);

	printf("%d", max);

	return 0;

}