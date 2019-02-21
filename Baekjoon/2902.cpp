#include<iostream>
#include<string>
#include<vector>
using namespace std;



int main(){
    string input;
    vector<char> ans;
    cin>> input;

    ans.push_back(input[0]);
    for(int i=1; i<input.size(); i++){
        if(input[i] == '-'){
            ans.push_back(input[i+1]);
        }
    }


    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
    }

    
    return 0;

}

