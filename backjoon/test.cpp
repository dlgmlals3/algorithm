#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0; 
int V, E;

struct Edge {
    Edge(int u_, int v_, int d_) : u(u_), v(v_), d(d_) {}
    int u, v, d;
};

vector<Edge> edges;
int group[10001];
int ranks[10001];

bool compare(const Edge &e1, const Edge &e2) {
    return e1.d < e2.d;
}

int Find(int u) {
    if (u == group[u]) return u;
    return group[u] = Find(group[u]);
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (ranks[u] < ranks[v]) {
        swap(u, v);
    }
    group[v] = u;
    if (ranks[u] == ranks[v]) {
        ranks[u]++;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V >> E;
    for (int i=0; i<E; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        edges.push_back(Edge(u, v, d));
    }
    for (int i=1; i<=V; i++) {
        group[i] = i;
    }
    
    // KRUSCAL
    sort(edges.begin(), edges.end(), compare);

    for (Edge edge : edges) {
        int u = Find(edge.u);
        int v = Find(edge.v);
        if (u != v) {
            ans += edge.d;
            Union(u, v);
        }
    }
    cout << ans << '\n';
    return 0;
}