#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

#define SIZE 50001
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

vector<Edge> edges[SIZE];
int K;
int n, m, t;
int s, g, h;

int diskjtra(int startVertex, int endVertex) {
    vector<int> dist(SIZE, INF);
    vector<bool> check(SIZE, false);
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
    cin >> K;
    while (K--) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        for (int i=0; i<m; i++) {
            int s, e, d;
            cin >> s >> e >> d;
            edges[s].push_back(Edge(e, d));
            edges[e].push_back(Edge(s, d));
        }

        vector<int> ans;
        for (int i=0; i<t; i++) {
            int dest;
            cin >> dest;
            int path1 = diskjtra(s, g) + diskjtra(g, h) + diskjtra(h, dest);
            int path2 = diskjtra(s, h) + diskjtra(h, g) + diskjtra(g, dest);
            int origin = diskjtra(s, dest);
            if (origin == path1) {
                ans.push_back(dest);
            } else if (origin == path2) {
                ans.push_back(dest);
            }
        }

        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        } cout << '\n';

        for (int i=1; i<=n; i++) {
            edges[i].clear();
        }
    }
    return 0;
}