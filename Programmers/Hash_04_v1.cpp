#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int cmp(pair<string,int> a, pair<string,int> b){
    return a.second > b.second;
}

int cmp_2(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<int, int> indexing;
    map<string,int> playlist;
    map<string, vector< pair<int, int> > > origin_number_list;

    vector< pair<string, int > > v_pair;
    
    for(int i=0; i<genres.size(); i++){
        playlist[genres[i]] += plays[i];
        origin_number_list[genres[i]].push_back({plays[i],i});
    }
    
    for(map<string,int>::iterator it = playlist.begin(); it != playlist.end(); it++)
        v_pair.push_back({(*it).first, (*it).second});
    
    
    sort(v_pair.begin(), v_pair.end(), cmp);
    
    for(int i=0; i<v_pair.size(); i++){
        sort(origin_number_list[v_pair[i].first].begin(), origin_number_list[v_pair[i].first].end(), cmp_2);
        
        for(int j=0; j< origin_number_list[v_pair[i].first].size() && j < 2; j++)
            answer.push_back(origin_number_list[v_pair[i].first][j].second);
        
    }
    
    
    return answer;
}