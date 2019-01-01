#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>//For using std::find in gcc
using namespace std;

#define SEARCHING 0
#define SEARCHED 2

int main()
{
	int T;
	vector<int> count;
	scanf("%d", &T);

	//테스트 케이스 T 반복
	for (int i = 0; i < T; i++)
	{
		//Define
		vector<int> status;
		vector<int> buf;
		map<int, int> pair;
		int searched = 0;
		int connets = 0;

		//Input
		int n;
		scanf("%d", &n);
		status.resize(n + 1);
		status.assign(status.size(), SEARCHING);
		status[0] = -1;

		for (int i = 1; i <= n; i++)
		{
			int temp;
			scanf("%d", &temp);
			pair.insert(make_pair(i, temp));
		}

		int start = -1;
		int temp;

		//아직 탐색하지못한 start 지점 찾기
		for (int i=1; searched !=n; i++)
		{

			if (status[i] == SEARCHING)
			{
				start = i;
				temp = i;

				//연결고리 1세트를 찾기
				for (int i = 1; i <= (n - connets) + 1; i++)
				{
					//짝조사
					if (status[temp] == SEARCHING)
					{
						status[temp] = SEARCHED; //조사완료하고
						searched++; // searched 값을 증가시킨다음
						buf.push_back(temp); //연결고리로 추정되는 예비후보들을 buf에 넣어둠
						temp = (pair[temp]); // 다음 짝 검사
					}

					//6자형 연결고리 탐색 그렇지 않은경우는 모두 탈출
					else if (status[temp] == SEARCHED)
					{
						//연결고리를 발견하면
						vector<int>::iterator itr = find(buf.begin(), buf.end(), temp);
						if (itr != buf.end())
							connets += buf.size() - (itr - buf.begin()); // 연결고리 시작지점부터 끝지점까지 연결고리 개수를 저장
						break;
					}
				}
				buf.clear();

			}
		}

		count.push_back(n - connets);
	}

	for (int i = 0; i < count.size(); i++)
		printf("%d\n", count[i]);

	return 0;
}