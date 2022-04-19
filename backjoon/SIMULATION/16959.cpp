#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <queue>
#include <string.h>

using namespace std;

int N;

vector<vector<int>> v(11, vector<int>(11, 0));
map<int, pair<int, int>> m;

// kngiht, queen, look
int dky[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dkx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dqy[] = {1, 1, -1, -1};
int dqx[] = {1, -1, -1, 1};
int dly[] = {0, 0, 1, -1};
int dlx[] = {1, -1, 0, 0};

int visit[11][11][133][4];
int ans = -1;

void bfs() {
    memset(visit, -1, sizeof(visit));

    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(m[1].first, m[1].second, 1, 0));
    q.push(make_tuple(m[1].first, m[1].second, 1, 1));
    q.push(make_tuple(m[1].first, m[1].second, 1, 2));
    visit[m[1].first][m[1].second][1][0] = 0;
    visit[m[1].first][m[1].second][1][1] = 0;
    visit[m[1].first][m[1].second][1][2] = 0;

    while (!q.empty()) {
        int y, x, move, horse;
        tie(y, x, move, horse) = q.front();
        q.pop();
        int time = visit[y][x][move][horse];

        if (move == N*N) {
            if (ans == -1 || ans > visit[y][x][move][horse]) {
                ans = visit[y][x][move][horse];
            }
            return;
        }

        for (int i=0; i<3; i++) {
            if (i == horse) continue;
            if (visit[y][x][move][i] != -1) continue;
            q.push(make_tuple(y, x, move, i));
            visit[y][x][move][i] = time+1;
        }
        
        if (horse == 0) {
            for (int i=0; i<8; i++) {
                int ny = y + dky[i];
                int nx = x + dkx[i];
                int newMove = move;
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;                
                if (v[ny][nx] == newMove + 1) newMove++;
                if (visit[ny][nx][newMove][horse] != -1) continue;
                q.push(make_tuple(ny, nx, newMove, horse));
                visit[ny][nx][newMove][horse] = time+1;
            }
        }
        else if (horse == 1) {
            for (int i=0; i<4; i++) {
                for (int j=1;;j++) {
                    int ny = y + (dqy[i] * j);
                    int nx = x + (dqx[i] * j);
                    int newMove = move;
                    if (ny < 0 || ny >= N || nx < 0 || nx >= N) break;
                    if (v[ny][nx] == newMove+1) newMove++;
                    if (visit[ny][nx][newMove][horse] != -1) continue;
                    q.push(make_tuple(ny, nx, newMove, horse));
                    visit[ny][nx][newMove][horse] = time+1;
                }
            }
        }
        else {
            for (int i=0; i<4; i++) {
                for (int j=1;;j++) {
                    int ny = y + (dly[i] * j);
                    int nx = x + (dlx[i] * j);
                    int newMove = move;
                    if (ny < 0 || ny >= N || nx < 0 || nx >= N) break;
                    if (v[ny][nx] == newMove+1) newMove++;
                    if (visit[ny][nx][newMove][horse] != -1) continue;
                    q.push(make_tuple(ny, nx, newMove, horse));
                    visit[ny][nx][newMove][horse] = time+1;
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> v[i][j];
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            m[v[i][j]] = make_pair(i, j);
        }
    }

    bfs();
    cout << ans << endl;
    return 0;
}