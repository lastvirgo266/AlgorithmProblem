#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;


inline int ParseAlphabet(char a){

    return a-65;
}

bool cmp(int a, int b){
    return a > b;
}

int main(){


    int value = 0;
    vector<int> result;
    result.resize(30);

    for(int i=0;i<result.size(); i++)
        result[i] = 0;


    int N;

    scanf("%d",&N);

    for(int i=0; i<N; i++){
        string temp;
        
        cin>>temp;
        reverse(temp.begin(),temp.end());

        for(int i=0; i<temp.size(); i++){
            result[ParseAlphabet(temp[i])] += pow(10,i);
        }

    }

    sort(result.begin(), result.end(), cmp);

    for(int i=0; i<result.size(); i++){
        value += result[i]*(9-i);
    }
    
    printf("%d",value);
    return 0;
}