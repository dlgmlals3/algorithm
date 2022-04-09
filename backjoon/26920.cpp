#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int N, M, P;
vector<int> S(10, 0);
vector<vector<char>> m(1001, vector<char>(1001, ' '));
vector<vector<int>> visit(1001, vector<int>(1001, -1));
queue<tuple<int, int, int>> q[10];
vector<int> ans(10, 0);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> P;
    for (int i=1; i<=P; i++) {
        cin >> S[i];
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> m[i][j];
            
            if (m[i][j] >= '1' && m[i][j] <= '9') {
                int index = m[i][j]-'0';
                q[index].push(make_tuple(i, j, m[i][j]-'0'));
                visit[i][j] = m[i][j]-'0';
            }
        }
    }
   
    while(true) {
        bool modiefied = false;    
        for (int i=1; i<=P; i++) {
            if (!q[i].empty()) {
                int y, x, castle;
                tie(y, x, castle) = q[i].front();
                ans[castle]++;
                q[i].pop();

                for (int j=0; j<4; j++) {
                    for (int k=1; k<=S[i]; k++) {
                        int ny = y + (dy[j]*k);
                        int nx = x + (dx[j]*k);
                        if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
                        if (m[ny][nx] == '#') break;
                        if (visit[ny][nx] != -1) break; // continue ?
                        if (m[ny][nx] == '.') {
                            q[i].push(make_tuple(ny, nx, m[ny][nx]-'0'));
                            visit[ny][nx] = m[ny][nx]-'0';
                        }
                    }
                }
                modiefied = true;
            }
        }
        
        if (!modiefied) {
            break;
        }
    }


    for (int i=1; i<=9; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}