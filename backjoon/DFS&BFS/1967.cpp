#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 10001

using namespace std;

int N;
vector<pair<int, int>> edges[MAX];
vector<bool> check(MAX, false);
vector<int> dist(MAX, 0);

void dfs(int cur) {
    for (auto e : edges[cur]) {
        int next = e.first, d = e.second;
        if (check[next]) continue;
        check[next] = true;
        dist[next] = dist[cur] + d;
        dfs(next);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    
    for (int i=0; i<N-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }
    check[1] = true;
    dfs(1);
    int maxD = 0;
    int maxV = 0;
    for (int i=1; i<=N; i++) {
        if (maxD < dist[i]) {
            maxD = dist[i];
            maxV = i;
        }
    }
    fill(dist.begin(), dist.end(), false);
    fill(check.begin(), check.end(), false);

    check[maxV] = true;
    dfs(maxV);
    maxD = 0;
    for (int i=1; i<=N; i++) {
        maxD = max(maxD, dist[i]);
    }
    cout << maxD << '\n';
    return 0;
}