#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


int map[100][100] = {0,};
int y_len = 3;
int x_len = 3;

int R,C,K;

void Test(){
    printf("\n");

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++)
            printf("%d ",map[i][j]);
    printf("\n");
    }


    printf("\n \n");

}


int Change(){

    if(x_len >= y_len){
        //Row Change
        int new_x_len = 0;
        for(int i=0; i<y_len; i++){


            int x_count = 0;

            //reverse_arr (i ==> NUMBER, result ==>COUNT)
            int reverse_arr[101] = {0,};

            //arr[i][j] ( i==> COUNT, j==> index, result ==> NUMBER)
            vector< vector < int > > arr;
            arr.resize(101);

            //Get
            for(int j=0; j<x_len; j++){
                reverse_arr[map[i][j]]++;
            }

            //Sort
            for(int j=0; j<101; j++){
                if(reverse_arr[j] > 0){
                    arr[reverse_arr[j]].push_back(j);
                    if(arr[reverse_arr[j]].size() > 1)
                        sort(arr[reverse_arr[j]].begin(), arr[reverse_arr[j]].end());
                }
            }

            //Copy
            for(int count = 1, j = 0; count<arr.size(); count++){
                for(int index =0; index<arr[count].size(); index++){
                    map[i][j++] = arr[count][index];
                    map[i][j++] = count;
                    x_count++;
                }

            }

            if(x_count+1 < x_len)
                for(int j=x_count+1; j<x_len; j++)
                    map[i][j] = 0;


            new_x_len = new_x_len > x_count ? new_x_len : x_count;
        }

        x_len = new_x_len;

    }


    else{
        //column Change
        int new_y_len = 0;
        for(int j=0; j<x_len; j++){


            int y_count = 0;

            //reverse_arr (i ==> NUMBER, result ==>COUNT)
            int reverse_arr[101] = {0,};

            //arr[i][j] ( i==> COUNT, j==> index, result ==> NUMBER)
            vector< vector < int > > arr;
            arr.resize(101);

            //Get
            for(int i=0; i<y_len; i++){
                reverse_arr[map[i][j]]++;
            }

            //Sort
            for(int i=0; i<101; i++){
                if(reverse_arr[i] > 0){
                    arr[reverse_arr[i]].push_back(i);
                    if(arr[reverse_arr[i]].size() > 1)
                        sort(arr[reverse_arr[i]].begin(), arr[reverse_arr[i]].end());
                }
            }

            //Copy
            for(int count = 1, i = 0; count<arr.size(); count++){
                for(int index =0; index<arr[count].size(); index++){
                    map[i++][j] = arr[count][index];
                    map[i++][j] = count;
                    y_count++;
                }
            }

            if(y_count+1 < y_len)
                for(int i=y_count+1; i<y_len; i++)
                    map[i][j] = 0;


            new_y_len = new_y_len > y_count ? new_y_len : y_count;
        }

        y_len = new_y_len;

    }


    return map[R][C];

}




int main(){

    scanf("%d %d %d", &R, &C, &K);
    R--, C--;

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            scanf("%d",&map[i][j]);

    int T = 0;

    Test();

    if(map[R][C] == K);

    else
        while( Change() != K){
            T++;
            Test();
        }

    
    printf("%d",T);
    return 0;
}