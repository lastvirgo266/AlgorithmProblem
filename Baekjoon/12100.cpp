#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<stack>
using namespace std;


short board[20][20];
int max = -1;

//----Test Module START---//
void BoardPrint(int number){
    for(int i=0; i<number; i++){
        for(int j=0; j<number; j++)
            printf("%d",board[i][j]);
        printf("\n");
    }
    printf("\n\n");
}
//----Test Module END ---//


int SearchMax(vector< vector<short> > map){
    int max = -1;
    int temp =0;

    for(int i=0; i<map.size(); i++){
        for(int j=0; j<map.size(); j++){
            temp = map[i][j];
            max = max > temp ? max : temp;
        }
    }

    return max;
}


vector< vector<short> > solve(vector< vector<short> > map, int x_direction, int y_direction){

    int start_y = 0;
    int start_x = 0;

    int end_y = 0;
    int end_x = 0;
    
    if(y_direction == 0){

        end_x = x_direction > 0 ? map.size()-1 : 0;
        start_x = end_x == 0 ? map.size()-1 : 0;

        for(int j = start_x; j != end_x; j += x_direction){
            for(int i= start_y; i != end_y; i++){
                map[i][j+x_direction] = map[i][j] == map[i][j+x_direction] ? 
                map[i][j]+map[i][j+x_direction] : map[i][j+x_direction]; 
            }
        }

    }
    
    else{
        for(int i = start_y; i != end_y; i += y_direction){
            for(int j; j != end_x; j++){

            }
        }
    }

}


int main(){
    int number;




}