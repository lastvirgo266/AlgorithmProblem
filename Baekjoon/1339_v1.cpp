#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;




int main(){
    vector< string > words;

    int N;

    words.resize(N);

    for(int i=0; i<words.size(); i++){
        scanf("%s",&words[i]);
        reverse(words[i].begin, words[i].end);
    }
    



    return 0;
}