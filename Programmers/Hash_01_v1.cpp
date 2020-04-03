#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multimap<string, int> mm;
    
    for(int i=0; i<participant.size(); i++){
        mm.insert({participant[i], 1});
    }
    
    for(int i=0; i<completion.size(); i++){
        mm.erase(mm.find(completion[i]));
    }
    
    for (multimap<string,int>::iterator it =mm.begin(); it!=mm.end(); ++it){
        answer = (*it).first;
    }
    

    return answer;
}