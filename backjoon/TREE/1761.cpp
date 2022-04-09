// LCA
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<pair<int, int>> edges[40001];
vector<bool> visit(40001);
vector<int> parent(40001);
vector<int> depth(40001);
vector<int> dist(40001);

int lca(int u, int v) {
   if (depth[u] > depth[v]) {
       swap(u, v);
   }
   while (depth[u] != depth[v]) {
       v = parent[v];
   }
   while (u != v) {
       v = parent[v];
       u = parent[u];
   }
   return u;   
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i=0; i<N-1; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        edges[u].push_back(make_pair(v, d));
        edges[v].push_back(make_pair(u, d));
    }    

    queue<int> q;
    q.push(1);
    parent[1] = 0;
    depth[1] = 0;
    dist[1] = 0;
    visit[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto it : edges[cur]) {
            int next = it.first;
            int d = it.second;
            if (visit[next]) continue;
            visit[next] = true;
            depth[next] = depth[cur] + 1;
            parent[next] = cur;
            dist[next] = dist[cur] + d;
            q.push(next);
        }
    }

    cin >> M;
    for (int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        //cout << " u : " << u << " v : " << v << " " << lca(u, v) << endl;
        //cout << "dist[u]" << dist[u] << " " << dist[v] << " " << 
        cout << dist[u] + dist[v] -(2 * dist[lca(u, v)]) << '\n';
    }
    return 0;
}