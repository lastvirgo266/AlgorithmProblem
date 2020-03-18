#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


int N,M,K;


int fert[10][10] ={ 0, };
int direction[8][2] = { {1,0}, {-1,0}, {1,1}, {1, -1}, {-1,1}, {-1, -1}, {0,1}, {0,-1} };

int robot_fert[10][10] = {0,};

vector< vector < vector < int> > > map;
vector < vector < vector <int> > > destroy;


void InitMap(){
    map.resize(10);

    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            map[i].resize(10);
}

void InitDestroy(){
    destroy.resize(10);

    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            destroy[i].resize(10);
}


int CountTree(){
    int count = 0;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            count += map[i][j].size();

    
    return count;


}


void SortMapAgeASC(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(map[i][j].size()>2)
                sort(map[i][j].begin(), map[i][j].end());
}


void Spring(){

    InitDestroy();

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            
            for(int k=0; k<map[i][j].size(); k++){
                
                //양분 흡수할수있으면 흡수해버리기
                if(fert[i][j] - map[i][j][k] >=0){
                    fert[i][j] -= map[i][j][k];
                    map[i][j][k] *= 2;
                }
                
                else{
                    destroy[i][j].push_back(map[i][j][k]);
                    map[i][j].erase(map[i][j].begin() + k);
                    k--;
                }

            }


        }


}

void Summer(){

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            
            //죽은것들 양분 뿌리기
            for(int k=0; k<destroy[i][j].size(); k++){
                fert[i][j] += destroy[i][j][k]/2;
            }
            
        }


    destroy.clear();

}


void Fall(){

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){

            for(int k=0; k<map[i][j].size(); k++){

                for(int i=0; i<8; i++){
                    
                    if(map[i][j][k] % 5 != 0)
                        continue;
                    
                    int move_y = direction[i][0];
                    int move_x = direction[i][1];
                    
                    //나무를 심자
                    if(0<= move_y && move_y <N &&
                       0<= move_x && move_x <N){
                           map[move_y][move_x].push_back(1);
                       }


                }

            }


        }

}


void Winter(){
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++){
            fert[i][j] += robot_fert[i][j];
        }

    SortMapAgeASC();
}


int main(){
    
    InitMap();
    scanf("%d %d %d", &N, &M, &K);


    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d",&robot_fert[i][j]);
    

    for(int i=0; i<M; i++){
        int y,x,age;

        //문제와 실제푸는데 인덱스를 맞추기위한 조정
        y--, x--;
        scanf("%d %d %d",&y, &x, &age);
        map[y][x].push_back(age);
    }
    
    Winter();

    while (K--){
        Spring();
        Summer();
        Fall();
        Winter();
    }

    printf("%d", CountTree());

    return 0;

}