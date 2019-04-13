#include<iostream>
#include<vector>
#define MAX 18
using namespace std;


inline bool PrimeCheck(int A){ for(int i=2; i<A; i++){ if(A % i == 0) return false;} return true; }

int main(){
    double A,B=0;
    int primer = 0;
    double dp[MAX+1][MAX+1][MAX+1]={0, };

    cin>>A;
    cin>>B;

    A /= 100;
    B /= 100;


    dp[1][0][0] = (1-A)*(1-B); //Nobody goal
    dp[1][0][1] = (1-A)*B; //B goal
    dp[1][1][0] = A*(1-B); //A goal
    dp[1][1][1] = A*B; //A, B goal

    for(int n=2; n<=MAX; n++){
        for(int i=0; i<=MAX; i++){
            for(int j=0; j<=MAX; j++){
                if(i+1<=MAX) dp[n][i+1][j] = dp[n-1][i][j]*A*(1-B);
                if(j+1<=MAX) dp[n][i][j+1] = dp[n-1][i][j]*(1-A)*B;
                if(i+1<=MAX && j+1<=MAX) dp[n][i+1][j+1] = dp[n-1][i][j]*A*B;
                if(n+1 <=MAX) dp[n][i][j] = dp[n-1][i][j]*(1-A)*(1-B);
            }

        }

    }

    double result = 0;

    for(int i=0; i<=MAX; i++)
        for(int j=0; j<=MAX; j++)
            if(PrimeCheck(dp[18][i][j])) result += dp[18][i][j];

    cout<<result<<endl;
    return 0;

}