#include <string>
#include <vector>



using namespace std;

vector<int> s1 = {1,2,3,4,5};
vector<int> s2 = {2,1,2,3,2,4,2,5};
vector<int> s3 = {3,3,1,1,2,2,4,4,5,5};




vector<int> solution(vector<int> answers) {
    
    int s1Score = 0;
    int s2Score = 0;
    int s3Score = 0;
    
    vector<int> answer;

    for(int i=0; i<answer.size(); i++){

        s1Score = s1[i%s1.size()] == answer[i] ? ++s1Score : s1Score;
        s2Score = s2[i%s2.size()] == answer[i] ? ++s2Score : s2Score;
        s3Score = s3[i%s3.size()] == answer[i] ? ++s3Score : s3Score;

    }

    
    

    return answer;
}