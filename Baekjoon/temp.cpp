#include <stdio.h>
#include <queue>
#include <stdlib.h>

#define SUCCESS 333

using namespace std;

// #Pair

char board[100][100] = {};
int x_weight[4] = {1,-1,0,0};
int y_weight[4] = {0,0,1,-1};
int visited[100][100][2]= {{{0, }, } ,};


//Test Module

void PrintBoard(){
	for(int i = 0; i<9; i++){
		for(int j= 0; j<8; j++){
			if(board[i][j] != 0)
				printf("%c",board[i][j]);
		}

		printf("\n");

	}

	printf("\n");

	
}
	



struct Point{
	int r_x;
	int r_y;
	
	int b_x;
	int b_y;

    int move_count;
};

Point MoveBead(Point point, int x_weight, int y_weight){

	//Check visited
	if( (visited[point.r_y][point.r_x][0] == 1) && (visited[point.b_y][point.b_x][1] == 1)){
		point.move_count = -1;
		return point;
	}

	//moving more than 10, it is not executed
	if(point.move_count == 10){
		point.move_count = -1;
		return point;
	}


	board[point.r_y][point.r_x] = 'R';
	board[point.b_y][point.b_x] = 'B';


	//Test
	//PrintBoard();


	//If set
	if(abs(point.r_x - point.b_x) == abs(x_weight) && 
	   abs(point.r_y - point.b_y) == abs(y_weight)){

		//Moving
		if(point.r_x - point.b_x == x_weight || point.r_y - point.b_y == -(y_weight)){
			while(board[point.r_y+ y_weight][point.r_x + x_weight] == '.'||
			      board[point.b_y + y_weight][point.b_x + x_weight] == '.'){


				if(board[point.r_y+ y_weight][point.r_x + x_weight] == '.' ){
					board[point.r_y][point.r_x] = '.';
					point.r_x += x_weight;
					point.r_y += y_weight;
					board[point.r_y][point.r_x] = 'R';
				}


				if(board[point.b_y+ y_weight][point.b_x + x_weight] == '.'){
					board[point.b_y][point.b_x] = '.';
					point.b_x += x_weight;
					point.b_y += y_weight;
					board[point.b_y][point.b_x] = 'B';
				}

				//Test
				//PrintBoard();
			}


		}

		//Moving
		else{
			while(board[point.b_y+ y_weight][point.b_x + x_weight] == '.'||
				  board[point.r_y + y_weight][point.r_x + x_weight] == '.'){


				if(board[point.b_y+ y_weight][point.b_x + x_weight] == '.' ){
					board[point.b_y][point.b_x] = '.';
					point.b_x += x_weight;
					point.b_y += y_weight;
					board[point.b_y][point.b_x] = 'B';
				}


				if(board[point.r_y+ y_weight][point.r_x + x_weight] == '.'){
					board[point.r_y][point.r_x] = '.';
					point.r_x += x_weight;
					point.r_y += y_weight;
					board[point.r_y][point.r_x] = 'R';
				}

				//Test
				//PrintBoard();
			}
		}



		board[point.r_y][point.r_x] = '.';
		board[point.b_y][point.b_x] = '.';


		if(board[point.r_y+ y_weight][point.r_x + x_weight] == 'O'){
			if(abs(point.r_x - point.b_x) == abs(x_weight) && 
			abs(point.r_y - point.b_y) == abs(y_weight)){
				point.move_count = -1;
				return point;
			}

			else{
				point.move_count++;
				point.move_count += SUCCESS;
				return point;
			}
		}


		if(board[point.b_y+ y_weight][point.b_x + x_weight] == 'O'){
			point.move_count = -1;
			return point;
		}


		point.move_count++;
		return point;
		

	}


	//Not set
	while(board[point.b_y+ y_weight][point.b_x + x_weight] == '.' || 
		  board[point.r_y+ y_weight][point.r_x + x_weight] == '.'){

		//Test
		//PrintBoard();


		if(board[point.r_y+ y_weight][point.r_x + x_weight] == '.' ){
			board[point.r_y][point.r_x] = '.';
			point.r_x += x_weight;
			point.r_y += y_weight;
			board[point.r_y][point.r_x] = 'R';
		}


		if(board[point.b_y+ y_weight][point.b_x + x_weight] == '.'){
			board[point.b_y][point.b_x] = '.';
			point.b_x += x_weight;
			point.b_y += y_weight;
			board[point.b_y][point.b_x] = 'B';
		}

	}


	//Test
	//PrintBoard();
	printf("%d\n",point.move_count);

	board[point.r_y][point.r_x] = '.';
	board[point.b_y][point.b_x] = '.';


	if(board[point.b_y+ y_weight][point.b_x + x_weight] == 'O'){
		//Test
		//PrintBoard();
		point.move_count = -1;
		return point;
	}


	if(board[point.r_y+ y_weight][point.r_x + x_weight] == 'O'){

		if(abs(point.r_x - point.b_x) == abs(x_weight) && 
	   	   abs(point.r_y - point.b_y) == abs(y_weight)){
			point.move_count = -1;
			return point;
		}

		else{
		point.move_count++;
		point.move_count += SUCCESS;
		return point;
		}
	}



	point.move_count++;
	return point;

}



int main(){

	for(int i=0; i<100; i++)
		for(int j=0; j<100; j++)
			for(int k=0; k<2; k++)
				visited[i][j][k] = 0;


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

		for(int j=0; j<x; j++){
			char temp;
			while((temp = getchar()) == '\n' );
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


	Point temp;
	temp.r_x = 4;
	temp.r_y = 1;

	temp.b_x = 3;
	temp.b_y = 7;
	temp.move_count = 0;

    

    for(int i =0; i<4; i++){
        Point t;
        t = MoveBead(temp, x_weight[i], y_weight[i]);
        printf("%d\n",t.move_count);
    }

	return 0;
    
}