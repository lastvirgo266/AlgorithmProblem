//#include<stdio.h>
//#include<vector>
//using namespace std;
//
//#define ROW 0
//#define COL 1
//#define VAL 2
//
//vector < vector<int*> > stickerOrder;
//vector< vector<int> > sticker;
//vector<int> score;
//int totalScore = 0;
//
//inline int MAX(int a, int b) { return a > b ? a : b; }
//
//
//void StickerSort(int *number, int *row, int *col)
//{
//
//	if (stickerOrder.size() == 0)
//	{
//		stickerOrder.resize(1);
//		stickerOrder[0].resize(3);
//		stickerOrder[0][ROW] =  row;
//		stickerOrder[0][COL] = col;
//		stickerOrder[0][VAL] = number;
//	}
//
//
//
//
//	//Sticker Order top
//	int i = stickerOrder.size() - 1;
//	vector<int*>  temp;
//	temp.resize(3);
//
//	while (*stickerOrder[i][VAL] < *number) 
//	{
//		i--;
//	}
//
//
//	temp[ROW] = row;
//	temp[COL] = col;
//	temp[VAL] = number;
//
//	stickerOrder.insert(stickerOrder.end() - i, 1, temp);
//
//
//}
//
//
//
////vector<int> GetOverlap(vector<int> target)
////{
////	vector<int> temp;
////
////	if (target[ROW] == 1)
////	{
////
////
////		if ((target[COL] >1) && (target[VAL] == sticker[target[ROW]][target[COL - 1]]))
////		{
////			temp.push_back(target[ROW]);
////			temp.push_back(target[COL]);
////			return temp;
////		}
////
////		if ((target[COL] < sticker[ROW].size()-1) &&  (target[VAL] == sticker[target[ROW]][target[COL + 1]]))
////		{
////			temp.push_back(target[ROW]);
////			temp.push_back(target[COL]);
////			return temp;
////		}
////
////		if (target[VAL] == sticker[target[ROW + 1]][target[COL]])
////		{
////			temp.push_back(target[ROW]);
////			temp.push_back(target[COL]);
////			return temp;
////		}
////
////		else
////		{
////			return temp;
////		}
////
////	}
////
////
////
////	if (target[ROW] == 2)
////	{
////
////
////		if ((target[COL] >1) && (target[VAL] == sticker[target[ROW]][target[COL - 1]]))
////		{
////			temp.push_back(target[ROW]);
////			temp.push_back(target[COL]);
////			return temp;
////		}
////
////		if ((target[COL] < sticker[ROW].size() - 1) && (target[VAL] == sticker[target[ROW]][target[COL + 1]]))
////		{
////			temp.push_back(target[ROW]);
////			temp.push_back(target[COL]);
////			return temp;
////		}
////
////		if (target[VAL] == sticker[target[ROW -1 1]][target[COL]])
////		{
////			temp.push_back(target[ROW]);
////			temp.push_back(target[COL]);
////			return temp;
////		}
////
////		else
////		{
////			return temp;
////		}
////
////	}
////
////
////}
//
//
//void ScoreGet(vector<int*> information)
//{
//	if (*information[ROW] > 1)
//		sticker[*information[ROW] - 1][*information[COL]] = -1;
//	else
//		sticker[*information[ROW] + 1][*information[COL]] = -1;
//
//
//	if (*information[COL] > 1)
//		sticker[*information[ROW]][*information[COL] - 1] = -1;
//
//
//	if(*information[COL] < stickerOrder[1].size()-1)
//		sticker[*information[ROW]][*information[COL] + 1] = -1;
//
//
//	totalScore += *information[VAL];
//
//	sticker[*information[ROW]][*information[COL]] = -1;
//	*information[VAL] = -1;
//
//}
//
//
//void TakeSticker(vector< vector<int*> > stack)
//{
//	vector<int*> temp;
//	vector<int> max;
//	max.resize(stack.size());
//
//
//
//	for (int i = 0; i < stack.size(); i++)
//	{
//
//
//		if (*stack[i][ROW] > 1)
//		{
//			if (sticker[*stack[i][ROW]-1][*stack[i][COL]] != *stack[i][VAL])
//				max[i] = MAX(max[i],sticker[*stack[i][ROW] - 1][*stack[i][COL]]);
//
//		}
//
//
//		else
//		{
//			if (sticker[*stack[i][ROW]+1][*stack[i][COL]] != *stack[i][VAL])
//				max[i] = MAX(max[i], sticker[*stack[i][ROW] + 1][*stack[i][COL]]);
//		}
//
//
//
//
//		if (*stack[i][COL] > 1)
//		{
//			if (sticker[*stack[i][ROW]][*stack[i][COL] - 1] != *stack[i][VAL])
//				max[i] = MAX(max[i],sticker[*stack[i][ROW]][*stack[i][COL] - 1]);
//		}
//
//
//		if (*stack[i][COL] < sticker[1].size() - 1)
//		{
//			if(sticker[*stack[i][ROW]][*stack[i][COL] + 1] != *stack[i][VAL])
//				max[i] = MAX(max[i], sticker[*stack[i][ROW]][*stack[i][COL] + 1]);
//		}
//
//
//
//	}
//
//	
//	
//
//
//
//
//}
//
//
//
//
//
//
//
//
//
//void StickerGet()
//{
//	vector< vector<int*> > tempStack;
//	int i = stickerOrder.size() - 1;
//	
//
//	while (stickerOrder.size() != 0)
//	{
//
//		if (*stickerOrder[i][VAL] == -1)
//		{
//			
//			continue;
//			
//			
//		}
//
//
//		else
//		{
//
//
//
//
//			if (stickerOrder.size() > 1)
//			{
//
//
//
//				
//				if (*stickerOrder[i][VAL] == *stickerOrder[i - 1][VAL])
//				{
//					tempStack.push_back(stickerOrder[i]);
//
//
//				}
//
//				else
//				{
//					
//
//
//					
//				}
//
//
//
//
//
//			}
//
//
//
//
//
//		}
//
//
//
//
//		
//
//
//
//
//
//	}
//
//
//
//
//	
//}
//
//
//
//
//
//
//
//
//int main()
//{
//
//	sticker.resize(3);
//
//	int N;
//	scanf("%d", &N);
//
//
//	for (int i = 1; i <= 3; i++)
//		sticker[i].resize(N + 1);
//
//
//
//
//	for (int i = 1; i <= N; i++)
//	{
//		int number;
//
//		scanf("%d", &number);
//
//
//		sticker[1][i] = number;
//
//
//
//
//
//
//
//	}
//
//	
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//}




#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))
long long a[100001][2];
long long d[100001][3];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i][0]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i][1]);
		}
		d[0][0] = d[0][1] = d[0][2] = 0;
		for (int i = 1; i <= n; i++) {
			d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2])); // 이 식때문에
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + a[i][0];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + a[i][1];
		}
		long long ans = 0;

		
		for (int i = 1; i <= n; i++) {
			ans = max(max(ans, d[i][0]), max(d[i][1], d[i][2])); // 이 코드는 필요 없지 않나요??
		}
		printf("%lld\n", ans);
	}
	return 0;
}