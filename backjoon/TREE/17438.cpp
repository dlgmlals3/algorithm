#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define MAXNODE 100001
using namespace std;

int N, M;
vector<int> edges[MAXNODE];
vector<bool> visit(MAXNODE, false);
vector<vector<int>> ancestor(MAXNODE, vector<int>(18, 0)); // 2^17 = 131072
vector<int> parent(MAXNODE, 0);
vector<int> depth(MAXNODE, 0);
int MAX_POW = 0;

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    
    // depth[u] == depth[v]
    for (int i=MAX_POW; i>=0; i--) {
        if (depth[u] - (1<<i) >= depth[v]) {
            u = ancestor[u][i];
        }
    }
    
    if (u != v) {
        for (int i=MAX_POW; i>=0; i--) {
            if (ancestor[u][i] != ancestor[v][i]) {
                u = ancestor[u][i];
                v = ancestor[v][i];
            } 
        }
        return ancestor[u][0];
    } else {
        return u;
    }
}

void dfs(int node) {
    visit[node] = true;
    for (int next : edges[node]) {
        if (visit[next]) continue;
        parent[next] = node;
        depth[next] = depth[node] + 1;
        dfs(next);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    MAX_POW = (int)floor(log2(N));

    for (int i=0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    dfs(1);
    
    for (int i=1; i<=N; i++) {
        ancestor[i][0] = parent[i];
    }
    for (int j=1; j<=MAX_POW; j++) {
        for (int i=1; i<=N; i++) {
            ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
        }
    }
    
    cin >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }

    return 0;
}