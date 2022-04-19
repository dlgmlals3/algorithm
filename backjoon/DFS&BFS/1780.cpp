#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int m[2200][2200];
vector<int> cnt(3, 0); // -1, 0, 1

bool isSameNumber(int r, int c, int dist) {
    int num = m[r][c];
    for (int i=r; i<r+dist; i++) {
        for (int j=c; j<c+dist; j++) {
            if (m[i][j] != num) {
                return false;                
            }
        }
    }
    return true;
}

void dfs(int r, int c, int dist) {
    if (dist == 1 || isSameNumber(r, c, dist)) {
        if (m[r][c] == -1) {
            cnt[0]++;
        } else if(m[r][c] == 0) {
            cnt[1]++;
        } else {
            cnt[2]++;
        }
        return;
    }

    int newDist = dist / 3;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            dfs(r + newDist*i, c + newDist*j, newDist);
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
            cin >> m[i][j];
        }
    }
    dfs(0, 0, N);
    cout << cnt[0] << endl << cnt[1] << endl << cnt[2] << endl;
    return 0;
}