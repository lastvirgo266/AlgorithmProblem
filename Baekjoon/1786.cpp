#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<int> getPi(string p){
    int m = p.size();
    int j = 0;
    vector<int> pi(m,0);

    for(int i=1; i<m; i++){ //i : length of sub string
        while(j > 0 && p[i] != p[j])
            j = pi[j-1];

        if(p[i] == p[j])
            pi[i] = ++j;
        
    }

    return pi;

}


vector<int> KMP(string s, string p){
    vector<int> ans;

    auto pi = getPi(p);

    int n = s.size();
    int m = p.size();
    int j = 0;

    for(int i=0; i<n; i++){
        while(j>0 && s[i] != p[j])
            j = pi[j-1];

        if(s[i] == p[j]){
            if(j == m-1){
                ans.push_back(i-(m-1) + 1);
                j = pi[j];
            }

            else
                j++;
        }


    }

    return ans;

}



int main(){
    string s,p;

    getline(cin, s);
    getline(cin, p);

    vector<int> ans = KMP(s,p);

    cout<<ans.size()<<endl;

    for(auto i : ans)
        printf("%d\n",i);
        //cout<<i<<endl; //cout -->시간 초과 오류

    return 0;


}


// AAABAAAABAAAA
// AAABAAAA


//참고, 출처 : https://bowbowbow.tistory.com/6
