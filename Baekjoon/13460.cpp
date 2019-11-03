#include <stdio.h>
#include <queue>
#include <math.h>

#define SUCCESS 333

using namespace std;

// #Pair

char board[100][100];
int x_weight[4] = {1,-1,0,0};
int y_weight[4] = {0,0,1,-1};
int visited[100][100]= {0,};



struct Point{
	int r_x;
	int r_y;
	
	int b_x;
	int b_y;

    int move_count;
};

Point MoveBead(Point point, int x_weight, int y_weight){

	//Check visited
	if(visited[point.r_y][point.r_x] == 1 && visited[point.b_y][point.b_x] == 1){
		point.move_count = -1;
		return point;
	}

	//moving more than 10, it is not executed
	if(point.move_count == 10){
		point.move_count = -1;
		return point;
	}




	//If set
	if(abs(point.r_x - point.b_x) == 1 && abs(point.r_y - point.b_y) == 1){
		if(point.r_x - point.b_x == x_weight || point.r_y - point.b_y == y_weight){
			while(board[point.r_y+ y_weight][point.r_x + x_weight] == '.'){
				point.r_x += x_weight;
				point.b_x += x_weight;

				point.r_y += y_weight;
				point.b_y += y_weight;
			}
		}

		else{
			while(board[point.b_y+ y_weight][point.b_x + x_weight] == '.'){
				point.r_x += x_weight;
				point.b_x += x_weight;

				point.r_y += y_weight;
				point.b_y += y_weight;
			}
		}

		if(board[point.r_y+ y_weight][point.r_x + x_weight] == 'O'){
			point.move_count++;
			point.move_count += SUCCESS;
			return point;
		}

		else if(board[point.r_y+ y_weight][point.r_x + x_weight] == 'O'){
			point.move_count = -1;
			return point;
		}


		point.move_count++;
		return point;
		

	}


	//Not set
	while(board[point.b_y+ y_weight][point.b_x + x_weight] == '.' || 
		  board[point.r_y+ y_weight][point.r_x + x_weight] == '.'){



		if(board[point.r_y+ y_weight][point.r_x + x_weight] == '.'){
			point.r_x += x_weight;
			point.r_y += y_weight;
		}

		if(board[point.b_y+ y_weight][point.b_x + x_weight] == '.'){
			point.b_x += x_weight;
			point.b_y += y_weight;
		}

		if(board[point.r_y+ y_weight][point.r_x + x_weight] == 'O'){
			point.move_count = -1;
			return point;
		}

		else if(board[point.r_y+ y_weight][point.r_x + x_weight] == 'O'){
			point.move_count++;
			point.move_count += SUCCESS;
			return point;
		}


	}





	if(board[point.r_y+ y_weight][point.r_x + x_weight] == 'O'){
		point.move_count = -1;
		return point;
	}

	else if(board[point.r_y+ y_weight][point.r_x + x_weight] == 'O'){
		point.move_count++;
		point.move_count += SUCCESS;
		return point;
	}


	point.move_count++;
	return point;

}





int main(){

	queue<Point> queue;

	int y;
	int x;

	int start_r_x;
	int start_r_y;

	int start_b_x;
	int start_b_y;

	scanf("%d", &y);
	scanf("%d", &x);

	fflush(stdin);

	for(int i=0; i<y; i++){
		fflush(stdin);

		for(int j=0; j<x; j++){
			char temp;
			scanf("%c", &temp);
			board[i][j] = temp;

			if(temp == 'R'){
				start_r_x = j;
				start_r_y = i;
				board[i][j] = '.';
			}

			else if(temp == 'B'){
				start_b_x = j;
				start_b_y = i;
				board[i][j] = '.';
			}

		}

	}

	for(int i=0; i<y; i++){
		for(int j=0; j<x; j++){
			printf("%c",board[i][j]);
		}

		printf("\n");
	}


	Point temp;
	temp.r_x = start_r_x;
	temp.r_y = start_r_y;

	temp.b_x = start_b_x;
	temp.b_y = start_b_y;
	temp.move_count = 0;

	queue.push(temp);


	while(!queue.empty()){
		Point prev = queue.front();
		queue.pop();


		for(int i=0; i<4; i++){
			Point temp;

			temp = MoveBead(prev, x_weight[i], y_weight[i]);

			if(temp.move_count > SUCCESS){
				printf("%d",temp.move_count);
				return 0;
			}

			else if(temp.move_count > 0){
				queue.push(temp);
			}

		}

		visited[prev.r_y][prev.r_x] = 1;
		visited[prev.b_y][prev.b_x] = 1;




	}

    

	return 0;
    
}