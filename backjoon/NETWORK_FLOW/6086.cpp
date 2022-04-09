#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    Edge(int e, int c) : end(e), capa(c) {}
    int end;
    int capa;
    Edge *prev;
};

vector<Edge *> edges[701];
vector<bool> check(701, false);
int N;
int source;
int sink;

void addEdge(int s, int e, int c) { 
    Edge *next = new Edge(e, c);
    Edge *prev = new Edge(s, 0);
    next->prev = prev;
    prev->prev = next;
    edges[s].push_back(next);
    edges[e].push_back(prev);
}

int dfs(int x, int c) {
    if (check[x]) return 0;
    check[x] = true;
    if (x == sink) return c;
    
    for (int i=0; i<edges[x].size(); i++) {
        if (edges[x][i]->capa > 0) {
            int curCapa = edges[x][i]->capa;
            if (c != 0 && c < curCapa) {
                curCapa = c;
            }
            int f = dfs(edges[x][i]->end, curCapa);
            if (f) {
                edges[x][i]->capa -= f;
                edges[x][i]->prev->capa += f;
                return f;
            }
        }
    }
    return 0;
}

int flow() {
    int ans = 0;
    while (true) {
        fill(check.begin(), check.end(), false);
        int f = dfs(source, 0);
        if (f == 0) break;
        ans += f;
    }
    return ans;
}

////////
int node(char s) {
    if (s >= 'A' && s <= 'Z') {
        return s - 'A';
    } else {
        return s - 'a' + 26;
    }
}

int main(void) {
    cin >> N;
    source = 0;
    sink = 'Z' - 'A';
    for (int i=0; i<N; i++) {
        char u, v;
        int f;
        cin >> u >> v >> f;
        addEdge(node(u), node(v), f);
        addEdge(node(v), node(u), f);
    }    
    
    cout << flow() << endl;
    return 0;
}
