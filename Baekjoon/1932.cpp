#include<iostream>
#include<vector>
#define TRIANGLE(n) n*(n+1)/2
#define LEFT(n, index) n + index
#define RIGHT(n, index) n+1 + index

using namespace std;
inline int GetMax(int a, int b){ return a > b ? a : b; }

int max_level;
vector<int> triangle_number;
int memoi[TRIANGLE(500)] = { NULL, };


int GetTrianglePassSum(int now_level, int now_index)
{
	if (now_level > max_level)
		return 0;

	if (memoi[now_index] != NULL)
		return memoi[now_index];

	int max = -1;

	//Search left and right
	max = GetMax(GetTrianglePassSum(now_level + 1, LEFT(now_level,now_index)), GetTrianglePassSum(now_level + 1, RIGHT(now_level,now_index)));

	memoi[now_index] = max + triangle_number[now_index];

	return memoi[now_index];
}



int main()
{
	cin >> max_level;
	triangle_number.resize(TRIANGLE(max_level));

	for (int i = 0; i < triangle_number.size(); i++)
		cin >> triangle_number[i];

	cout << GetTrianglePassSum(1, 0);






}