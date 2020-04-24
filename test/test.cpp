
#include<stdio.h>
#include<math.h>

int answer = 0;
int _answer = 0;


int solve(int n, int sub){
    int ret = 0;


    if(n < 1 || n < pow(3, sub/2)) return 0;

    if( n == 3){
        if(sub == 2){
            answer++;
            return 1;
        }

        return 0;
    }



    if(n%3 == 0 && sub >= 2){
        ret += solve(n/3, sub-2);
    }

    ret += solve(n-1, sub+1);

    return ret;

}


int main(){

    for(int i=5; i<=2147483647; i++){

        _answer =  solve(i, 0);

        if(answer != _answer)
            printf("%d %d %d",answer, _answer, i);
        answer =0;
        _answer = 0;
    }



}