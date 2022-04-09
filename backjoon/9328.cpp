#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
#include <algorithm>

#define MAX_H 150
#define MAX_W 150
using namespace std;

int N;
int H, W;
vector<vector<char>> m(MAX_H, vector<char>(MAX_W, ' '));
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int ans = 0;
string keys;

bool bfs() {
    string test = "test";
    queue<pair<int, int>> q;
    vector<vector<bool>> check(MAX_H, vector<bool>(MAX_W, false));
    //memset(check, false, sizeof(check));

    q.push(make_pair(0, 0));
    check[0][0] = true;
    bool modified = false;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny > H || nx < 0 || nx > W) continue;
            if (m[ny][nx] == ' ') continue;
            if (m[ny][nx] == '*') continue;
            if (check[ny][nx]) continue;

            if (m[ny][nx] == '.') {
                q.push(make_pair(ny, nx));
                check[ny][nx] = true;

            } else if (m[ny][nx] >= 'A' && m[ny][nx] <= 'Z') { // door
                // cout << "keys : " << keys << endl;
                auto it = keys.find(tolower(m[ny][nx]));
                if (it != string::npos) { // open door
                    m[ny][nx] = '.';
                    q.push(make_pair(ny, nx));
                    check[ny][nx] = true;
                }

            } else if (m[ny][nx] >= 'a' && m[ny][nx] <= 'z') { // save key
                keys.push_back(m[ny][nx]);
                m[ny][nx] = '.';
                modified = true;
                q.push(make_pair(ny, nx));
                check[ny][nx] = true;
            } else if (m[ny][nx] == '$') { 
                ans++;
                modified = true;
                m[ny][nx] = '.';
            }
        }
        
    }
    return modified;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    while (N--) {
        ans = 0;
        cin >> H >> W;
        H++; W++;

        fill(m.begin(), m.end(), vector<char>(MAX_H, ' '));
        keys.clear();
        for (int i=0; i<=H; i++) {
            for (int j=0; j<=W; j++) {
                m[i][j] = '.';
            }
        }
        for (int i=1; i<H; i++) {
            for (int j=1; j<W; j++) {
                cin >> m[i][j];
            }
        }
        cin >> keys;
        while (bfs()) {}

        cout << ans << endl;
    }
    return 0;
}