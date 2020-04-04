#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> parsed_string;
    
    for(int i=0; i<numbers.size(); i++){
        parsed_string.push_back(to_string(numbers[i]));
    }
    
    sort(parsed_string.begin(), parsed_string.end(),cmp);
    //if (parsed_string.at(0) == "0")        return "0";
    
    for(int i=0; i<parsed_string.size(); i++){
        answer += parsed_string[i];
    }
    
    
    return answer;
}