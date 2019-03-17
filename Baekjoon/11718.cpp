#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main(){
    int count=0;
    vector<string> input_save;

    while(count++ < 100){
        string input;
        getline(cin, input);
        input_save.push_back(input);
        
        if(!cin) //EOF Checking
            break;
    }


    for(auto i : input_save)
        cout<<i<<endl;


    return 0;
}