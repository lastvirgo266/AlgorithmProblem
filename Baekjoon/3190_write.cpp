/*
1. 덱을 이용해 일종의 스택 형식으로 사용
2. 헤드를 조회하고 이동한 헤드를 일단 맨 끝에 올려둠
3. 그다음에 맨 끝에 올려둔 헤드가 사과의 위치인지 아닌지 검사
4. 사과이면 그대로 냅둠(이동할 필요가 없음)
5. 사과가 아니면 꼬리를 짜름(이동하는 것을 생각하면 헤드가 이동하고 꼬리가 사라지는 형태임)
*/

#include<iostream>
#include<deque>



using namespace std;


int idx[4]={0, 1,0,-1};
int idy[4]={1, 0, -1, 0};
int N;
int map[101][101];
int visited[101][101];

pair<int, char>change[101];
deque<pair<int, int>> q;



int dir; //현재 방향



int main()
{

	int K, L;
	int a, b;
	char c;
	int i, j;
	int sec=0; //초정보
	int x, y;
	int tmpx, tmpy;
	pair<int, int> tmp;

	

    //N 입력
	scanf("%d", &N);



    //map 초기화
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			map[i][j]=0;



	scanf("%d", &K);



    //사과 위치 입력
	for(i=0; i<K; i++){
		scanf("%d %d", &a, &b);
		map[a-1][b-1]=1; //사과위치, 0부터 index사용하면서 [a][b]로 해둬서 틀렸었다.
	}

		

	scanf("%d", &L);



	for(i=0; i<L; i++)
	{
		scanf("%d %c", &a, &c);
		change[i].first = a; //시간초
		change[i].second = c; //바꿀 방향
	}



	dir = 0; //처음 방향은 오른쪽

	

	x = 0; 
	y = 0;

	

    //시작점 집어넣음
	q.push_back(make_pair(x, y));



	a=0;



	while(q.size() > 0)
	{

		sec++;  //1초가 지났음 



        //꼬리부분을 조회(꺼내는거 아님)
		tmp = q.back();

    
        //방향대로 이동
		x = tmp.first+idx[dir];
		y = tmp.second+idy[dir];



		if(visited[x][y] == 1 || 
			x < 0 || x >=N ||
			y < 0 || y >=N)
			break; //벽을 박아서 종료



        //이동한 다음에 뒤에 집어넣음
		q.push_back(make_pair(x, y));



        //이동한 것을 마킹
		visited[x][y]=1;




        //사과가 있으면 먹고 삭제
		if(map[x][y] == 1){

			map[x][y]=0;

		}



		else{
			tmp = q.front();

			visited[tmp.first][tmp.second] = 0;

			q.pop_front();
		}




		if(a < L && sec == change[a].first) //방향바꿔야하면
		{

			if(change[a++].second == 'D')

				dir = (dir+1+4)%4;

			else

				dir = (dir-1+4)%4;
		}



	}



	printf("%d\n", sec);

	

}