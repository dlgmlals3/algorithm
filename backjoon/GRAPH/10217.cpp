#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>

using namespace std;

struct Edge {
    Edge(int e, int c, int t) : end(e), cost(c), time(t) {}
    int end;
    int cost;
    int time;
};

int T;
const int COST_MAX = 10000;
const int VERTEX_MAX = 100;
const int INF = 10001 * 101;
vector<Edge> edges[10001];
vector<vector<int>> d(101, vector<int>(10001, INF)); // V, cost = time;


struct compare {
    bool operator()(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
        int av, ac, at;
        int bv, bc, bt;
        tie(av, ac, at) = a;
        tie(bv, bc, bt) = b;
        if (at > bt) {
            return true;
        }
        return false;
    }
};


int main(void) {
    cin >> T;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        for (int i=0; i<K; i++) {
            int u, v, c, t;
            cin >> u >> v >> c >> t;
            edges[u].push_back(Edge(v, c, t));
        }

        // vertex, cost, time
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, compare> q;
        vector<bool> check(VERTEX_MAX, false); 
        q.push(make_tuple(1, 0, 0));
        for (int i=0; i<=COST_MAX; i++) d[1][i] = 0;
        
        while (!q.empty()) {
            int v, c, t;
            tie(v,c,t) = q.top();
            q.pop();
                        
            for (Edge edge : edges[v]) {
                int nextVertex = edge.end;
                int nextCost = edge.cost + c;
                int nextTime = edge.time + t;
                
                if (nextCost > M) continue;
                if (d[nextVertex][nextCost] == INF || d[nextVertex][nextCost] > nextTime) {


                    d[nextVertex][nextCost] = nextTime;
                    q.push(make_tuple(nextVertex, nextCost, nextTime));
                                        
                    // next vertex에 도착했는데 비용이 많이드는 경로는 필요없음.
                    // 최소 next time값으로 time값을 세팅.
                    for (int i=nextCost+1; i<=M; i++){
                        if (d[nextVertex][i] <= nextTime) break;
                        d[nextVertex][i] = nextTime;
                    }
                }
            }
        }    

        int ans = INF;
        
        for (int i=0; i<=COST_MAX; i++) {
            ans = min(ans, d[N][i]);
        }
        if (ans == INF) {
            cout << "Poor KCM" << '\n';
        } else {
            cout << ans << '\n';
        }    
        
        // clear
        for (int i=0; i<K; i++) edges[i].clear();
        fill(d.begin(), d.end(), vector<int>(10001, INF));    
    }
   
    return 0;
}