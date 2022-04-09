#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<int> info;
vector<vector<int>> edges(20);
int answer = 1;

void dfs(int node, int ships, int wolfs, vector<pair<int, int>> el) {          
    if (info[node] == 0) {
        ships++;
    } else {
        wolfs++;
    }
    
    if (ships <= wolfs) {
        return;    
    }
    answer = max(answer, ships);
    
    for (int edge : edges[node]) {
        el.push_back(make_pair(node, edge));
    }
    

    for (int i=0; i<el.size(); i++) {
        vector<pair<int, int>> nl;
        for (int j=0; j<el.size(); j++) {
            if (i == j) continue;
            nl.push_back(el[j]);
        }
        
        int to = el[i].second;
        dfs(to, ships, wolfs, nl);
    }
    
}

int solution(vector<int> info_, vector<vector<int>> edges_) {
    N = info_.size();
    for (int i=0; i<N; i++) {
        info.push_back(info_[i]);
    }
 
    for (int i=0; i<edges_.size(); i++) {
        int from = edges_[i][0];
        int to = edges_[i][1];
        edges[from].push_back(to);
    }

    vector<pair<int, int>> el;
    dfs(0, 0, 0, el); 
    
    return answer;
}