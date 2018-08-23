#include<stdio.h>
#include<vector>
using namespace std;


struct Node 
{
	Node* prev = NULL;
	Node* next = NULL;
	short data = -1;

};

vector<Node> jose;
Node *startNode;




int Delete(Node *nowNode, int M)
{





	for (int i = 0; i < (M - 1); i++)
		nowNode = nowNode->next;

	Node* deleteNode = nowNode;
	int outputData;


	deleteNode->prev->next = deleteNode->next;
	deleteNode->next->prev = deleteNode->prev;
	nowNode = deleteNode->next;
	deleteNode->prev = NULL;
	deleteNode->next = NULL;
	outputData = deleteNode->data;


	//Move
	if ((nowNode->next) == NULL && (nowNode->prev == NULL))
	{
		printf("%d>", nowNode->data);
		return 0;
	}

	else
	{

		printf("%d, ", outputData);
		startNode = nowNode;
		return 1;
	}



}


int main()
{
	int N;
	scanf("%d", &N);

	int M;
	scanf("%d", &M);

	jose.resize(N);
	
	for (int i = 0; i < N; i++)
	{
		jose[i].data = i + 1;
		
		if (N == 1)
		{
			jose[i].next = &(jose[0]);
			jose[i].prev = &(jose[0]);
			break;
		}


		if (i == 0)
		{

			jose[i].next = &(jose[i + 1]);
			jose[i].prev = &(jose[N - 1]);
		}

		else if (i == N - 1)
		{
			jose[i].next = &(jose[0]);
			jose[i].prev = &(jose[i-1]);
		}

		else
		{
			jose[i].next = &(jose[i + 1]);
			jose[i].prev = &(jose[i - 1]);
		}

	}
	
	
	printf("<");
	startNode = &(jose[0]);


	while (Delete(startNode, M));



	return 0;



		



}