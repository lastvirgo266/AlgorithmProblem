#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;


int main(){
    vector<string> result;
    //Using to dictionary, because of time limit
    map<int, string> dict_name;
    map<string, int> dict_number;
    int N,M;

    //------INPUT-------//
    scanf("%d", &N);
    scanf("%d", &M);

    for(int i=1; i<=N; i++){
        string name;
        cin>>name;
        dict_name[i] = name;
        dict_number[name] = i;
    }

    //-----Working-----//
    for(int i=0; i<M; i++){
        string number;
        cin>>number;

        try //Input is number, Print name
        {
            //printf("%s\n",dict[stoi(number)/*Change string to integer*/].c_str()); //For C lannguage format using c_str()
            result.push_back(dict_name[stoi(number)]);
        }
        catch(const std::exception& e) //Input is name, print number
        {
            string name = number;
            result.push_back(to_string(dict_number[name]));
            
        }
        


    }

    //---OUTPUT----//
    for(int i=0; i< result.size(); i++){
        printf("%s\n",result[i].c_str());
    }


    return 0;



}