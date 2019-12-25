#include<stdio.h>
#include<vector>
using namespace std;

int cube[6][3][3] = { 
    { {1,2,3}, {4,5,6}, {7,8,9} },          //A
    { {10,11,12}, {13,14,15}, {16,17,18} }, //B
    { {19,20,21}, {22,23,24}, {25,26,27} }, //C
    { {28,29,30}, {31,32,33}, {34,35,36} }, //D
    { {37,38,39}, {40,41,42}, {43,44,45} }, //E
    { {46,47,48}, {49,50,51}, {52,53,54} }  //F
};



int reset_cube[6][3][3] = { 
    { {1,2,3}, {4,5,6}, {7,8,9} },          //A
    { {10,11,12}, {13,14,15}, {16,17,18} }, //B
    { {19,20,21}, {22,23,24}, {25,26,27} }, //C
    { {28,29,30}, {31,32,33}, {34,35,36} }, //D
    { {37,38,39}, {40,41,42}, {43,44,45} }, //E
    { {46,47,48}, {49,50,51}, {52,53,54} }  //F
};

int cube_collect[99][3][3];
int c = 0;


void test(){

    for(int z=0; z<6; z++){
        for(int y=0; y<3; y++){
              printf("%d %d %d\n",cube[z][y][0], cube[z][y][1], cube[z][y][2]);
            }
        printf("\n");
        }


    printf("--------------------------\n");

}

void reset(){

    for(int z=0; z<6; z++)
        for(int y=0; y<3; y++)
            for(int x=0; x<3; x++)
                cube[z][y][x] = reset_cube[z][y][x];

}


void print_save(){
    for(int i=0; i<c; i++){
    printf("#%d ", i+1);
        for(int  y=0; y<3; y++){
            printf("%d %d %d ", cube_collect[i][y][0], cube_collect[i][y][1], cube_collect[i][y][2]);
        }
        printf("\n");
    
    }


}

void save(int i){
i -=1;

 for(int y=0; y<3; y++)
    for(int x= 0; x<3; x++)
        cube_collect[c][y][x] = cube[i][y][x];
        

 c++;

 
}


void print(int z){

for(int y=0; y<3; y++){
 printf("%d %d %d\n",cube[z][y][0], cube[z][y][1], cube[z][y][2]);
}

}

void cubeRotate(int i){
int swap[3];
i -= 1;



    //Y - Axis Roate
    if(i >= 0 && i<= 5){
    
    
        if( i <=2 ){
        
        for(int j=0; j<3; j++){
            swap[j] = cube[1][j][i];
        }
        
        for(int j=0 ,j_d=2; j<3; j++, j_d--){
            cube[1][j][i] = cube[2][j][i];
            cube[2][j][i] = cube[3][j_d][i];
            cube[3][j_d][i] = cube[0][j][i];
            cube[0][j][i] = swap[j];
        }
        
        }
        
        else{
         i = i%3;
            for(int j=0; j<3; j++)
                swap[j] = cube[1][j][i];
        
        for(int j=0 ,j_d=2; j<3; j++, j_d--){
            cube[1][j][i] = cube[0][j][i];
            cube[0][j][i] = cube[3][j_d][i];
            cube[3][j_d][i] = cube[2][j][i];
            cube[2][j][i] = swap[j];
        }
        
        }
        
    }
    
    
    //X - Axis Rotate
    else if(i >=6 && i<=11){
    
        if(i <=8){
            i = i%3;
        for(int j=0; j<3; j++){
            swap[j] = cube[1][i][j];
        }
        
        
        for(int j=0,j_d=2; j<3; j++, j_d--){
            int k;
            if( i == 0)
             k = 2;
            else if (i ==2)
             k = 0;
            else
             k = 1;

            cube[1][i][j] = cube[5][i][j];
            cube[5][i][j] = cube[3][k][j_d];
            cube[3][k][j_d] = cube[4][i][j];
            cube[4][i][j] = swap[j];
        }
        
        
        }
        
        else{
         i = i%3;

        for(int j=0; j<3; j++){
            swap[j] = cube[1][i][j];
        }
         
        for(int j=0,j_d=2; j<3; j++, j_d--){
            int k;
            if( i == 0)
             k = 2;
            else if (i ==2)
             k = 0;
             else
             k = 1;

            cube[1][i][j] = cube[4][i][j];
            cube[4][i][j] = cube[3][k][j_d];
            cube[3][k][j_d] = cube[5][i][j];
            cube[5][i][j] = swap[j];
        }
         
        }
        
        
        
        
    
    }
    
    
}



int main() {

    int T;
    

   scanf("%d", &T);
    
   for(int i=0; i<T; i++){
    int M;
    int P;
    
    scanf("%d",&M);
    
    for(int m = 0; m<M; m++){
      int temp;
      scanf("%d",&temp);
      cubeRotate(temp);
      //printf("%d\n",m);
    }
    
    scanf("%d", &P);
    
    save(P);
    reset();
    
   
   }
   
   print_save();




    return 0;
}

