#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
const int INF = INT_MAX;

vector<vector<int>> v(101, vector<int>(101, INF));

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;

    for (int i=0; i<M; i++) {
        int s, e, d;
        cin >> s >> e >> d;   
        // 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
        // 최소값만 유지... 아놔 욕나오네;;
        v[s][e] = min(v[s][e], d);
    }

    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (v[i][k] == INF || v[k][j] == INF) continue;
                if (v[i][j] > v[i][k] + v[k][j]) {
                    v[i][j] = v[i][k] + v[k][j];
                }
            }
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (i == j || v[i][j] == INF) {
                v[i][j] = 0;
            }
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}