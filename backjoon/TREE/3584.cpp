#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T;
vector<int> edges[10001];
vector<int> parent(10001, 0);
vector<int> depth(10001, 0);
vector<bool> visit(10001, false);

int lca(int u, int v) {
    if (depth[u] > depth[v]) {
        swap(u, v);
    }
    while (depth[u] != depth[v]) {
        v = parent[v];
    }
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

void bfs(int root) {
    queue<int> q;
    q.push(root);   
    parent[root] = 0;
    depth[root] = 0; 
    visit[root] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : edges[cur]) {
            if (visit[next]) continue;
            parent[next] = cur;
            depth[next] = depth[cur] + 1;
            visit[next] = true;
            q.push(next);
        }
    }
}

int main(void) {    
    cin >> T;
    while (T--) {
        for (int i=0; i<10000; i++) edges[i].clear();
        fill(parent.begin(), parent.end(), 0);
        fill(depth.begin(), depth.end(), 0);
        fill(visit.begin(), visit.end(), false);

        int N;
        cin >> N;
        int u, v;
        for (int i=0; i<N-1; i++) {
            cin >> u >> v;
            parent[v] = u;
            edges[u].push_back(v);
        }

        int root = u;
        while (true) {
           if (parent[root] == 0) break;
           root = parent[root];
        }
        bfs(root);

        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }

    return 0;
}