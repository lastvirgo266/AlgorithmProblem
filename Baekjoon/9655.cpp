#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;

    //Stone must be left only one, So win
    if(N%2){
        cout<<"SK";
    }

    else{
        cout<<"CY";
    }

    

    return 0;

}