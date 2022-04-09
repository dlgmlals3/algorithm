#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> p(130, vector<int>(130, 0));

std::pair<int, int> operator +(const pair<int, int> &a, const pair<int, int>&b) {
    return std::make_pair(a.first + b.first, a.second + b.second);
}

bool isSameColor(int y, int x, int dist) {
    int color = p[y][x];
    for (int i=y; i<y+dist; i++) {
        for (int j=x; j<x+dist; j++) {
            if (p[i][j] != color) return false;
        }
    }
    return true;
}

pair<int, int> genPaper(int y, int x, int dist) {
    pair<int, int> sum(0, 0);
    // pair 끼리는 + operation 없어 ? 질문

    if (dist == 1 || isSameColor(y, x, dist)) {
        if (p[y][x] == 1){ 
            return make_pair(1, 0);
        } else {
            return make_pair(0, 1);
        }
    } else {
        int newDist = dist / 2;
        #if 0
        auto s1 = genPaper(y, x, newDist);
        auto s2 = genPaper(y + newDist, x, newDist);
        auto s3 = genPaper(y, x + newDist, newDist);
        auto s4 = genPaper(y + newDist, x + newDist, newDist);
        sum.first = s1.first + s2.first + s3.first + s4.first;
        sum.second = s1.second + s2.second + s3.second + s4.second;
        #else
        auto s1 = genPaper(y, x, newDist);
        auto s2 = genPaper(y, x + newDist, newDist);
        auto s3 = genPaper(y + newDist, x, newDist);
        auto s4 = genPaper(y + newDist, x + newDist, newDist);
        sum = s1 + s2 + s3 + s4;
        #endif
    }
    return sum;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> p[i][j];
        }
    }

    auto ans = genPaper(0, 0, N);
    cout << ans.second << endl;
    cout << ans.first << endl;
    return 0;
}