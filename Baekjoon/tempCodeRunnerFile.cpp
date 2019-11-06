#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<stack>
using namespace std;


int board[21][21];
int total_max = -1;
int x_direction[4] = {-1,1,0,0};
int y_direction[4] = {0,0,-1,1};

//----Test Module START---//
void BoardPrint(vector< vector<int> > map){
    for(int i=0; i<map.size(); i++){
        for(int j=0; j<map.size(); j++)
            printf("%d ",map[i][j]);
        printf("\n");
    }
    printf("\n\n");
}
//----Test Module END ---//


int SearchMax(vector< vector<int> > map){
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


vector< vector<int> > solve(vector< vector<int> > map, int x_direction, int y_direction){

    //Test
    //BoardPrint(map);

    int max = 0;

    int start_y = 0;
    int start_x = 0;

    int end_y = 0;
    int end_x = 0;
    
    // x -axis move
    if(y_direction == 0){

        start_x = x_direction > 0 ? map.size()-1 : 0;
        end_x = start_x == 0 ? map.size() : -1;
        end_y = map.size();
        start_y = 0;

        for(int i= start_y; i != end_y; i++){
            vector<int> arr; 
            for(int j = start_x; j != end_x; j -= x_direction){
                if(map[i][j] != 0){
                    arr.push_back(map[i][j]);
                    map[i][j] = 0;
                }
            }

            if(arr.size() != 0 ){
                //Test
                vector<int> new_arr;
                for(int i=0; i< arr.size()-1; i++){
                    if(arr[i] == arr[i+1]){
                        arr[i+1] += arr[i];
                        arr[i] = 0;
                        i++;

                    }

                    //Test
                }

                for(int i=0; i<arr.size(); i++){
                    if(arr[i] != 0)
                        new_arr.push_back(arr[i]);
                }

                //int j = (end_x - (x_direction)) - (new_arr.size()*(x_direction)-x_direction);
                int j = start_x;


                for(int count = 0; count < new_arr.size(); j -= x_direction, count++){
                    map[i][j] = new_arr[count];
                }
            }
        }


    }
    
    // y - axis move
    else{

        start_x = 0;
        end_x = map.size();
        start_y = y_direction > 0 ? map.size()-1 : 0;
        end_y = start_y == 0 ? map.size() : -1;

        for(int j = start_x; j != end_x; j++){
            vector<int> arr;
            for(int i = start_y; i != end_y; i -= y_direction){

                if(map[i][j] != 0){
                     arr.push_back(map[i][j]);
                     map[i][j] = 0;
                }
            }

            if(arr.size() != 0){
                vector<int> new_arr;
                for(int i=0; i< arr.size()-1; i++){
                    if(arr[i] == arr[i+1]){
                        arr[i+1] += arr[i];
                        arr[i] = 0;
                        i++;
                    }

                }

                for(int i=0; i<arr.size(); i++){
                    if(arr[i] != 0)
                        new_arr.push_back(arr[i]);
                }

                //int i = (end_y - (y_direction)) - (new_arr.size()*(y_direction)-y_direction);
                int i = start_y;

                for(int count = 0; count<new_arr.size(); i -= y_direction, count++){
                    map[i][j] = new_arr[count];
                }
            }
        }
    }


    max = SearchMax(map);

    total_max = total_max > max ? total_max : max;

    //Test
    //BoardPrint(map);
    //_sleep(3);

    return map;

}


int main(){
    //Init
    int number;
    vector< vector<int> > map;
    stack< vector< vector<int> > > stack_map;
    stack< int > stack_count;


    scanf("%d",&number);
    map.resize(number);

    for(int i=0; i<number; i++){
        map[i].resize(number);
        for(int j=0; j<number; j++){
            int temp;
            scanf("%d",&temp);
            map[i][j] = temp;
        }
    }

    stack_map.push(map);
    stack_count.push(0);


    while(!stack_map.empty()){
        vector< vector<int> > map = stack_map.top();
        int count= stack_count.top();

        stack_map.pop();
        stack_count.pop();

        //Test Count
        if(count < 5){
            for(int i=0; i<4; i++){
                vector< vector<int> > temp_map = solve(map, x_direction[i], y_direction[i]);
                stack_map.push(temp_map);
                stack_count.push(count+1);
            }

        }
        


    }

    printf("%d",total_max);
    
    //Test

    return 0;

}