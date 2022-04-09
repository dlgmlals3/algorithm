#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define MAXNODE 110000
using namespace std;

struct Edge {
    Edge(int v_, int d_) : v(v_), d(d_) {}
    int v;
    int d;
};

int N, M;
vector<Edge> edges[MAXNODE];
vector<bool> visit(MAXNODE, false);
vector<vector<int>> ancestor(MAXNODE, vector<int>(18, 0)); // 2^17 = 131072
vector<vector<int>> minLen(MAXNODE, vector<int>(18, 0)); // 2^17 = 131072
vector<vector<int>> maxLen(MAXNODE, vector<int>(18, 0)); // 2^17 = 131072
vector<int> parent(MAXNODE, 0);
vector<int> depth(MAXNODE, 0);
vector<int> dist(MAXNODE, 0);
int MAX_POW = 0;

pair<int, int> lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    pair<int, int> ans;
    ans.first = 10000000;
    ans.second = 0;

    for (int i=MAX_POW; i>=0; i--) {
        if (depth[u] - (1<<i) >= depth[v]) {
            ans.first = min(ans.first, minLen[u][i]);
            ans.second = max(ans.second, maxLen[u][i]);
            //cout <<" i : " << i << " u : " << u << " depth : " << depth[u] << " len: " << minLen[u][i] << " " << maxLen[u][i] << endl;
            u = ancestor[u][i];
        }
    }

    if (u != v) {
        for (int i=MAX_POW; i>=0; i--) {
            if (ancestor[u][i] == 0) continue;
            if (ancestor[u][i] != ancestor[v][i]) {
                ans.first = min(ans.first, minLen[u][i]);
                ans.second = max(ans.second, maxLen[u][i]);
                ans.first = min(ans.first, minLen[v][i]);
                ans.second = max(ans.second, maxLen[v][i]);
                u = ancestor[u][i];
                v = ancestor[v][i];
            } 
        }
        ans.first = min(ans.first, minLen[u][0]);
        ans.second = max(ans.second, maxLen[u][0]);
        ans.first = min(ans.first, minLen[v][0]);
        ans.second = max(ans.second, maxLen[v][0]);
    }
    return ans;
}

void dfs(int node) {
    visit[node] = true;
    for (Edge next : edges[node]) {
        if (visit[next.v]) continue;
        parent[next.v] = node;
        depth[next.v] = depth[node] + 1;
        dist[next.v] = next.d;
        dfs(next.v);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    MAX_POW = (int)floor(log2(N));
    MAX_POW-=1;

    for (int i=0; i<N-1; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        edges[u].push_back(Edge(v, d));
        edges[v].push_back(Edge(u, d));
    }
    
    dfs(1);
    
    for (int i=1; i<=N; i++) {
        ancestor[i][0] = parent[i];
        minLen[i][0] = dist[i];
        maxLen[i][0] = dist[i];
    }

    for (int j=1; j<=MAX_POW; j++) {
        for (int i=1; i<=N; i++) {
            ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
            minLen[i][j] = minLen[i][j-1];
            maxLen[i][j] = maxLen[i][j-1];
            if (ancestor[ancestor[i][j-1]][j-1] != 0) {
                if (minLen[i][j-1] >= 0) {
                    minLen[i][j] = min(minLen[i][j-1], minLen[minLen[i][j-1]][j-1]);
                }
                if (maxLen[i][j-1] >= 0) {
                    maxLen[i][j] = max(maxLen[i][j-1], maxLen[maxLen[i][j-1]][j-1]);
                }
            }
        }
    }
    
    cin >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        auto ans = lca(u, v);
        cout << ans.first << " " << ans.second << '\n';
    }

    return 0;
}