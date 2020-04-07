#include <string>
#include <vector>

using namespace std;

int completed[100] = {0,};
int ready[100] = {0,};

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    bool check = false;


    while(1){

        int count =0;

        for(int i=0; i<progresses.size(); i++){
            if(completed[i] != 1 || ready[i] != 1){
                check = true;
                progresses[i] += speeds[i];

                if(progresses[i] >= 100){
                    ready[i] = 1;
                }

            }
        }

        if(!check)
            return answer;


        for(int i=0; i<progresses.size(); i++){

            if(completed[i] != 1 || ready[i] != 1){

                if(progresses[i] >= 100){

                    if(i == 0 || completed[i-1] == 1){
                        count++;
                        completed[i] = 1;

                        for(int j=i+1; j<progresses.size(); j++){

                            if(ready[j-1] == 1 && completed[j] == 0 && ready[j] == 1){
                                completed[j] = 1;
                                count++;
                            }

                            else{
                                break;
                            }

                        }
                    }//End of nest for if statement
                }
            }
        }//End of for statement


        if(count > 0){
            answer.push_back(count);
        }



        check= false;


    }


    return answer;
}