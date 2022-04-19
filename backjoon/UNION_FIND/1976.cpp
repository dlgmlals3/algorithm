#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[201];
int level[201];

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
    parent[c] = p;
    if (level[p] == level[c]) {
        level[p] = level[c] + 1;
    }
} 

int main(void) {
    int N, M;
    cin >> N >> M;
    for (int i=1; i<=N; i++) parent[i] = i;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int v;
            cin >> v;
            if (v == 1) Union(i, j);
        }
    }

    bool ans = true;
    int parentV = -1;
    vector<int> citys;
    for (int i=0; i<M; i++) {
        int city;
        cin >> city;
        if (parentV == -1) {
            parentV = Find(city);
            continue;
        } 
        if (parentV != Find(city)) {
            ans = false;
            break;
        }
    }

    if (ans) 
        cout << "YES" << '\n';
    else 
        cout << "NO" << '\n';
    return 0;
}