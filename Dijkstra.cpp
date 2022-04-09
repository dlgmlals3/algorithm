#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    Edge(int e_, int d_): e(e_), d(d_) {}
    int e;
    int d;
};

struct compare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

vector<Edge> edges[801];
int N, E;
int V1, V2;

int diskjtra(int startVertex, int endVertex) {
    vector<int> dist(801, INF);
    vector<bool> check(801, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    q.push(make_pair(startVertex, 0));
    
    dist[startVertex] = 0;
    while (!q.empty()) {
        int cur = q.top().first;
        int cur_dist = q.top().second;
        q.pop();

        if(check[cur]) continue;
        check[cur] = true;
        
        for (auto edge : edges[cur]) {
            if (dist[edge.e] == INF || dist[edge.e] > dist[cur] + edge.d) {
                dist[edge.e] = dist[cur] + edge.d;
                q.push(make_pair(edge.e, dist[edge.e]));
            }
        }
    }
    return dist[endVertex];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);    
    cout.tie(nullptr);

    cin >> N >> E;

    for (int i=0; i<E; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        edges[s].push_back(Edge(e, d));
        edges[e].push_back(Edge(s, d));
    }

    cout << diskjtra(1, N) << '\n';

    for (int i=0; i<N; i++) {
        edges[i].clear();
    }
    return 0;
}