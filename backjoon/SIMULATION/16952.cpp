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

pair<int, int> visit[11][11][121][3];
pair<int, int> ans = make_pair(-1, -1);


void bfs() {
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            for (int k=0; k<=N*N; k++) 
                for(int l=0; l<3; l++) 
                    visit[i][j][k][l] = make_pair(-1, -1);

    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(m[1].first, m[1].second, 1, 0));
    q.push(make_tuple(m[1].first, m[1].second, 1, 1));
    q.push(make_tuple(m[1].first, m[1].second, 1, 2));
    visit[m[1].first][m[1].second][1][0] = make_pair(0, 0);
    visit[m[1].first][m[1].second][1][1] = make_pair(0, 0);
    visit[m[1].first][m[1].second][1][2] = make_pair(0, 0);

    while (!q.empty()) {
        int y, x, move, horse;
        tie(y, x, move, horse) = q.front();
        q.pop();
        auto &p = visit[y][x][move][horse];
        
        //
        if (move == N*N) {
            if (ans.first == -1 || ans > p) {
                ans = p;
            }
            
            //return;
        }
        
        for (int i=0; i<3; i++) {
            if (i == horse) continue;
            auto np = make_pair(p.first+1, p.second+1);
            if (visit[y][x][move][i].first == -1 || visit[y][x][move][i] > np) {
                visit[y][x][move][i] = np;
                q.push(make_tuple(y, x, move, i));
            }
        }
        
        if (horse == 0) {
            for (int i=0; i<8; i++) {
                int ny = y + dky[i];
                int nx = x + dkx[i];
                int newMove = move;
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;                
                if (v[ny][nx] == newMove + 1) newMove++;
                auto np = make_pair(p.first+1, p.second);
                
                if (visit[ny][nx][newMove][horse].first == -1 || np < visit[ny][nx][newMove][horse]) {
                    q.push(make_tuple(ny, nx, newMove, horse));
                    visit[ny][nx][newMove][horse] = np;
                }
            }
            //cout << "move : " << move << endl;
        }
        else if (horse == 1) {
            for (int i=0; i<4; i++) {
                for (int j=1;;j++) {
                    int ny = y + (dqy[i] * j);
                    int nx = x + (dqx[i] * j);
                    int newMove = move;
                    if (ny < 0 || ny >= N || nx < 0 || nx >= N) break;
                    if (v[ny][nx] == newMove+1) newMove++;
                    auto np = make_pair(p.first+1, p.second);

                    if (visit[ny][nx][newMove][horse].first == -1 || np < visit[ny][nx][newMove][horse]) {
                        q.push(make_tuple(ny, nx, newMove, horse));
                        visit[ny][nx][newMove][horse] = np;
                    }
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
                    auto np = make_pair(p.first+1, p.second);

                    if (visit[ny][nx][newMove][horse].first == -1 || np < visit[ny][nx][newMove][horse]) {
                        q.push(make_tuple(ny, nx, newMove, horse));
                        visit[ny][nx][newMove][horse] = np;
                    }
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
    cout << ans.first << " " << ans.second << endl;
    return 0;
}   