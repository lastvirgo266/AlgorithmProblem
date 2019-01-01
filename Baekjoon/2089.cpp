//#include<stdio.h>
//#include<vector>
//using namespace std;
//
//void BinaryChange(int number)
//{
//	vector<int> stack;
//	bool minus_check;
//
//	if (abs(number) == 1)
//	{
//		printf("1");
//		return;
//	}
//
//
//	if (number > 0)
//	{
//		minus_check = true;
//	}
//
//	else
//	{
//		number = -number;
//		minus_check = false;
//
//	}
//
//	int count = 0;
//
//
//
//	while (number != 0)
//	{
//		if (number % 2 == 0)
//		{
//			stack.push_back(0);
//		}
//
//		else
//			stack.push_back(1);
//
//		// -2승 처리해주기
//		
//
//
//		number /= 2;
//
//
//	}
//
//
//	if (minus_check)
//	{
//		stack.push_back(1);
//	}
//
//
//
//	for (int i = stack.size()-1; i >=0; i--)
//		printf("%d", stack[i]);
//
//
//
//}
//
//
//int main()
//{
//	
//	int number;
//	scanf("%d", &number);
//	BinaryChange(number);
//
//
//	return 0;
//
//
//
//
//
//
//}


#include<stdio.h>

int main()
{

	char buf[] = "Park";

	printf("%d", sizeof(buf));


	return 0;


}