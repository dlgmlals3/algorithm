// 이문제는 함정이란 함정과 약점을 다 밝혀낸문제
// vector 배열일때 sort... 다시 정리해....
// Planet planets[MAX];
//sort(planets+1, planets+1+N, compareX);
// MST + 응용
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

struct Edge {
    Edge(int u_, int v_, int d_) : u(u_), v(v_), d(d_) {}
    int u, v, d;
};

struct Planet {
    Planet() {}
    Planet(int idx_, int x_, int y_, int z_) : idx(idx_), x(x_), y(y_), z(z_) {}
    int idx;
    int x, y, z;
};

int N;
vector<Edge> edges;

vector<Planet> planets(MAX);

int group[100001];
int ranks[100001];

int Find(int u) {
    if (group[u] == u) return u;
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

bool compare(const Edge &e1, const Edge &e2) { 
    return e1.d < e2.d;
}

bool compareX(const Planet &p1, const Planet &p2) {
    return p1.x < p2.x;
}
bool compareY(const Planet &p1, const Planet &p2) {
    return p1.y < p2.y;
}
bool compareZ(const Planet &p1, const Planet &p2) {
    return p1.z < p2.z;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); //cout.tie(nullptr);

    cin >> N;
    
    for (int i=1; i<=N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        planets[i] = Planet(i, x, y, z);
        group[i] = i;
    }

 
    sort(planets.begin()+1, planets.begin()+1+N, compareX);
    for (int i=1; i<N; i++) {
        int diff = abs(planets[i].x - planets[i+1].x); // p is started 0
        edges.push_back(Edge(planets[i].idx, planets[i+1].idx, diff));
    }
    
    sort(planets.begin()+1, planets.begin()+1+N, compareY);
    for (int i=1; i<N; i++) {
        int diff = abs(planets[i].y - planets[i+1].y);
        edges.push_back(Edge(planets[i].idx, planets[i+1].idx, diff));
    }

    sort(planets.begin()+1, planets.begin()+1+N, compareZ);
    for (int i=1; i<N; i++) {
        int diff = abs(planets[i].z - planets[i+1].z);
        edges.push_back(Edge(planets[i].idx, planets[i+1].idx, diff));
    }

    sort(edges.begin(), edges.end(), compare);
    long long ans = 0;
    for (Edge e : edges) {
        int u = Find(e.u);
        int v = Find(e.v);
        if (u != v) {
            Union(u, v);
            ans += e.d;
        }
    }
    cout << ans << '\n';
    return 0;
}