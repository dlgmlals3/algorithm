// Minimum spanning Tree
// MST

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX 1001

using namespace std;

struct Edge {
    Edge(int u_, int v_, float d_) : u(u_), v(v_), d(d_) {}
    int u;
    int v;
    float d;
};

bool comapre(const Edge& e1, const Edge& e2) {
    if (e1.d <= e2.d) {
        return true;
    }
    return false;
}

vector<Edge> edges;
int parent[MAX];
int ranks[MAX];

int Find(int a) {
    if (parent[a] == a) 
        return a;
    return parent[a] = Find(parent[a]);
}

void Union(int p, int c) {
    p = Find(p);
    c = Find(c);
    if (ranks[p] < ranks[c]) {
        swap(p, c);
    }
    parent[c] = p;
    if (ranks[p] == ranks[c]) {
        ranks[p] = ranks[c] + 1;
    }
}

int main(void) {
    int N;
    cin >> N;
    for (int i=1; i<=N; i++) parent[i] = i;

    vector<pair<float, float>> coordies;
    coordies.push_back(make_pair(0.0, 0.0));
    for (int i=0; i<N; i++) {
        float u, v;
        cin >> u >> v;
        coordies.push_back(make_pair(u, v));
    }
    

    for (int i=1; i<=N-1; i++) {
        for (int j=i+1; j<=N; j++) {
            float v1 = pow(coordies[j].first - coordies[i].first, 2);
            float v2 = pow(coordies[j].second - coordies[i].second, 2);
            float d = sqrt(v2 + v1);
            edges.push_back(Edge(i, j, d));
        }
    }
    sort(edges.begin(), edges.end(), comapre);
    float ans = 0;
    for (Edge e : edges) {
        int u = Find(e.u);
        int v = Find(e.v);
        if (u != v) {
            ans += e.d;
            Union(u, v);
        }
    }
    cout << round(ans * 100) / 100 << '\n';

    return 0;
}