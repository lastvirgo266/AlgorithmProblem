#include<stdio.h>
#include<vector>
#define LEFT -1
#define RIGHT 1
#define LIVE 2
#define NOLIVE 0

inline int GetMinimum(int a, int b) {return a < b ? a : b; }


using namespace std;


vector<int> stick;


int tempAnts = 0;
int ants;





int main()
{
	int length;

	scanf("%d", &length);
	stick.resize(length + 1);
	
	scanf("%d", &ants);

	for (int i = 0; i < ants; i++)
	{
		int temp;
		scanf("%d", &temp);
		stick[temp] = 2;

	}

	





	return 0;
}