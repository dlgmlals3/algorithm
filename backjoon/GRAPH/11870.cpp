// warshal fluid + print path

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

int N, M;
#define INF INT_MAX

int routeCount = 0;
vector<vector<int>> dist(101, vector<int>(101, INF));
vector<vector<int>> route(101, vector<int>(101, INF));


void FindRoute(int i, int j) {
    if (route[i][j] == INF) return;
    FindRoute(i, route[i][j]);
    cout << route[i][j] << " ";
    FindRoute(route[i][j], j);
}

void GetRouteCnt(int i, int j) {
    if (route[i][j] == INF) return;
    routeCount++;
    GetRouteCnt(i, route[i][j]);
    GetRouteCnt(route[i][j], j);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i=0; i<M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        dist[u][v] = min(dist[u][v], d);
    }    

    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        route[i][j] = k;                
                    }
                }
            }
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) { 
            if (dist[i][j] == INF || i == j) {
                cout << "0" << '\n';
                continue;
            }
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) { 
            if (dist[i][j] == INF || i == j) {
                cout << "0" << '\n';
                continue;
            }
            routeCount = 2;
            GetRouteCnt(i, j);
            cout << routeCount << " ";
            cout << i << " ";
            FindRoute(i, j);
            cout << j << '\n';
        }
    }
    
    return 0;
}