#include <iostream>
#include <map>
#include <vector>
#define MAX 200001

using namespace std;

int index;
map<string, int> m;
vector<int> parent(MAX, 0);
vector<int> level(MAX, 0);
vector<int> frcnt(MAX, 1);

int Find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = Find(parent[v]);
}

void Union(int p, int c) {
    p = Find(p);
    c = Find(c);
    if (level[p] < level[c]) {
        swap(p, c);
    }
    // p c 같으면 이미 같은그룹....!!!!!!!!!!!!! 더해주면안됨 ㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠ
    if (p < c) {
        parent[c] = p;
        frcnt[p] += frcnt[c];
    } else if (p > c) {
        parent[p] = c;
        frcnt[c] += frcnt[p];
    }
    
    if (level[p] == level[c]) {
        level[p] = level[c] + 1;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        index = 1;
        m.clear();
        for (int i=1; i<MAX; i++) parent[i] = i;
        fill(level.begin(), level.end(), 0);
        fill(frcnt.begin(), frcnt.end(), 1);
        int F;
        cin >> F;

        vector<int> ans;
        for (int i=0; i<F; i++) {
            string a, b;
            cin >> a >> b;
             
            if (m.find(a) == m.end()) {
                m[a] = index++;
            }
            if (m.find(b) == m.end()) {
                m[b] = index++;
            }
            
            Union(m[a], m[b]);
            ans.push_back(frcnt[Find(m[a])]);
        }
        for (auto i : ans) cout << i << '\n';
    }    
    return 0;
}
