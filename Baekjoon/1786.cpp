#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main(){
    string plain;
    string find;
    int correct_index = 0;
    int next_correct_index = 0;
    int next_start_index = 0;
    int all_correct = 0;
    vector< int > ans;

    //공백포함 문자열 입력받기
    getline(cin,plain); 
    getline(cin,find);
    for(int i=0; i<plain.size(); /*  */){

        //plain과 find과 일치할때
        if(plain[i] == find[correct_index]){
            
            //찾고있는 과정중에 다음에 어떤 i 값이 들어가야하는지 수행하는 코드
            if(plain[i] == find[next_correct_index] && correct_index != 0){
                next_start_index = i;
                next_correct_index++;
                //cout<<"next OK : "<<next_start_index<<endl;//TEST
            } else{
                //cout<<"NEXT : "<<next_start_index<<endl; //TEST
                next_correct_index = 0;
                next_start_index = 0;
            }


            //모든것이 일치했을때
            if(correct_index == find.size()-1){
                ans.push_back(i-find.size()+2);
                all_correct++;

                //i 의 값을 정해야함
                if(next_correct_index != 0) {
                    i = next_start_index;
                    correct_index = next_correct_index;
                }

                else{
                    i++;   
                    correct_index = 0;
                    //cout<<i<<endl; //TEST
                }

                next_correct_index = 0;
                next_start_index = 0;
                //cout<<i<<endl; //TEST
                continue;
            }

            i++;
            correct_index++;
        }


        //중간에 안맞을 경우
        else{
            //cout<<"Prev :  "<<i<<" "<<next_correct_index<<endl; //TEST
            if(next_correct_index != 0) {
                i = next_start_index;
                correct_index = next_correct_index;
            }

            else{
                i++;   
                correct_index = 0;
                //cout<<i<<endl; //TEST
            }
            
            next_correct_index = 0;
            next_start_index = 0;
        }


    }


    
    cout<<all_correct<<endl;
    for(int i=0; i<ans.size(); i++){
        if(i == ans.size()-1){
            //cout<<ans[i];
            printf("%d",ans[i]);
        }

        else{
            //cout<<ans[i]<<" ";
            printf("%d ",ans[i]);
        }
    }


    return 0;

}


// AAABAAAABAAAA
// AAABAAAA