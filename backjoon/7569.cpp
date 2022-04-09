#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {1, -1, 0, 0, 0, 0};
int dh[] = {0, 0, 0, 0, 1, -1};

int M, N, H;
int tomato[102][102][102];
bool visit[102][102][102];
vector<tuple<int, int, int, int>> matured;
int ans = -1;

void printDebug() {
    for (int k=0; k<H; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                cout << tomato[k][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
}

bool isAllMatrued() {
    for (int k=0; k<H; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (tomato[k][i][j] == -1) continue;
                if (tomato[k][i][j] == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

void bfs() {
    if (isAllMatrued()) {
        ans = 0;
        return;
    }

    queue<tuple<int, int, int, int>> q;
    for (auto item : matured) {
        int h, y, x, t;
        tie(h, y, x, t) = item;
        q.push(make_tuple(h, y, x, t));
        visit[h][y][x] = true;
    }

    while (!q.empty()) {
        int h, y, x, t;
        tie(h, y, x, t) = q.front();
        q.pop();
        
        //cout << "time : " << t << endl << printDebug();        
        for (int i=0; i<6; i++) {
            int nh = h + dh[i];
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nh < 0 || nh >= H || ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (visit[nh][ny][nx]) continue;
            if (tomato[nh][ny][nx] == -1) continue;
            
            tomato[nh][ny][nx] = 1;
            visit[nh][ny][nx] = true;
            q.push(make_tuple(nh, ny, nx, t+1));

            if (isAllMatrued()) {
                if (ans == -1 || ans > t+1) {
                    ans = t+1;
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> M >> N >> H;
    
    for (int k=0; k<H; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                cin >> tomato[k][i][j];
                if (tomato[k][i][j] == 1) {
                    matured.push_back(make_tuple(k, i, j, 0));
                }
            }
        }
    }
    bfs();
    cout << ans << '\n';
    return 0;
}