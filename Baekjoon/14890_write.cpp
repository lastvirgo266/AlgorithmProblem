#include<stdio.h>

int L;
int N;


int FindPath(int board[][101]){

    int count = 0;

    
    //row search
    for(int i=0;i<N; i++){
        
        int current_height = board[i][0];
        int current_count = 1;
        int current_L = L;
        int start_slop = 0;
        int end_slope = 0;

        for(int j=1; j<N; j++){

            if(current_height == board[i][j] && start_slop == 0)
                current_count++;


            else{
                if(current_height - board[i][j] == 1 || current_height - board[i][j] == -1){
                    
                    if(start_slop == 0 && end_slope == 0){
                        
                        start_slop = current_height - board[i][j];
                        end_slope = 1;
                    }

                    //low --> height
                    if(start_slop == -1){
                        if(current_count - L >= 0){
                            start_slop = 0;
                            end_slope = 0;
                            current_L = L;
                            current_height = board[i][j];
                            current_count =1;
                        }
                        
                        else{
                            end_slope = -1;
                            break;
                        }

                    }

                    //height --> low
                    if(start_slop == 1){
                        if(current_height - board[i][j] != 1){
                            end_slope = -1;
                            break;
                        }

                        current_L--;

                        if(current_L == 0){
                            if(current_height - board[i][j] == 1){
                                current_L = L;
                                start_slop = 0;
                                end_slope = 0;
                                current_height = board[i][j];
                                current_count = 0;
                            }
                        }
                    }



                }

                else{
                    end_slope = -1;
                    break;
                }

            }


        }

            if(end_slope == 0){
                count++;
            }
    }


    return count;


}



int main(){
    int row_board[101][101] = {0,};
    int col_board[101][101] = {0,};

    scanf("%d", &N);
    scanf("%d", &L);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            scanf("%d",&(row_board[i][j]));
            col_board[j][i] = row_board[i][j];
        }



    /* 초기화 완료  */
    int count =0;

    count = FindPath(row_board) + FindPath(col_board);


    printf("%d",count);


    return 0;



}