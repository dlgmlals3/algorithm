// LCA
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[50001];
vector<bool> visit(50001, false);
vector<int> depth(50001, 0);
vector<int> parent(50001, 0);
int N, M;

int lca(int v1, int v2) {
    if (depth[v1] > depth[v2]) {
        swap(v1, v2);
    }
    while (depth[v2] != depth[v1]) {
        v2 = parent[v2];
    }
    while (v1 != v2) {
        v1 = parent[v1];
        v2 = parent[v2];
    }
    return v1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i=0; i<N-1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
    }
   
    queue<int> q;
    q.push(1);
    visit[1] = true;
    depth[1] = 0;
    parent[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : edge[cur]) {
            if (visit[next]) continue;
            depth[next] = depth[cur] + 1;
            parent[next] = cur;
            visit[next] = true;
            q.push(next);
        }
    }    
    cin >> M;
    for (int i=0; i<M; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        cout << lca(v1, v2) << '\n';
    }
}