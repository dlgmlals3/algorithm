#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<bool>> edge(501, vector<bool>(501, false));
vector<bool> check(501, false);
int n, m;

bool isCircle(int cur, int prev) {
    check[cur] = true;    
    for (int i=1; i<=n; i++) {
        if (cur == i || i == prev) continue;
        if (edge[cur][i]) {
            if (check[i]) return true;            
            if (isCircle(i, cur)) return true;
        }     
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int cnt = 1;
    while (true) {
        fill(edge.begin(), edge.end(), vector<bool>(501, false));
        fill(check.begin(), check.end(), false);
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i=0; i<m; i++) {
            int s, e;
            cin >> s >> e;    
            edge[s][e] = true;
            edge[e][s] = true;
        }

        int cycleCnt = 0;
        for (int i=1; i<=n; i++) {
            if (check[i]) continue;
            if (!isCircle(i, 0)) {
                cycleCnt++;
            }
        }

        if (cycleCnt == 0) {
            cout << "Case " << cnt << ": No trees." << '\n';
        } else if (cycleCnt == 1) {
            cout << "Case " << cnt << ": There is one tree." << '\n';
        } else {
            cout << "Case " << cnt << ": A forest of " << cycleCnt << " trees." << '\n';
        }
        cnt++;
    }
    return 0;
}