#include <iostream>
#include <climits>
#include <vector>
#include <queue>

#define INF INT_MAX

using namespace std;

struct Edge {
    Edge(int e_, int d_) : e(e_), d(d_) {}
    int e;
    int d;
};

int V, E, K;
vector<int> dist(20001, INF);    
vector<bool> check(20001, false);  
vector<Edge> edges[20001];

struct compare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second > b.second) {
            return true;
        }
        return false;
    }
};

// 다이스트라 dijkstra 알고리즘
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);    
    cout.tie(nullptr);

    cin >> V >> E;
    cin >> K;

    for (int i=0; i<E; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        edges[s].push_back(Edge(e, d));
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    q.push(make_pair(K, 0));
    dist[K] = 0;
    
    while (!q.empty()) {
        int cur = q.top().first;
        int cur_dist = q.top().second;
        q.pop();

        if (check[cur]) continue;
        check[cur] = true;
            
        for (Edge edge : edges[cur]) {    
            if (dist[edge.e] == INF || dist[edge.e] > dist[cur] + edge.d) {
                dist[edge.e] = dist[cur] + edge.d;
                q.push(make_pair(edge.e, dist[edge.e]));
            }
        }
    }

    for (int i=1; i<=V; i++) {
        if (i == K) {
            cout << "0" << '\n';
        } else if(dist[i] == INF) {
            cout << "INF" << '\n';
        } else {
            cout << dist[i] << '\n';
        }
    }
    return 0;
}