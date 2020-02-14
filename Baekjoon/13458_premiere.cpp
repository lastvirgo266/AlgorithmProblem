#include<stdio.h>
#include<vector>

using namespace std;

int main(){

    int N;
    vector<int> A;
    int B,C;

    scanf("%d",&N);
    A.resize(N);


    //시험장마다 응시자수 받음
    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        A[i] = temp;
    }


    scanf("%d", &B);
    scanf("%d", &C);


    /* 초기화 완료 */
    long long total = 0;

    for(int i=0; i<N; i++){
        int examinee = A[i];

        int need_watcher = 0;

        //총감독이 감시할수있는 수
        examinee -= B;

        if(examinee < 0)
            examinee = 0;


        need_watcher++;

        //부감독이 감시할수있는 수
        int share = (examinee / C);
        int remainder = (examinee % C); //올림을 위해 일부러 리마인드까지 구해줌

        if(remainder > 0){
            need_watcher++;
        }


        need_watcher += share;
        total += need_watcher;

    }

    printf("%lld", total);


    return 0;



}