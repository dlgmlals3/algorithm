#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int N;
vector<string> p;

bool isSameData(int y, int x, int dist) {
    char d = p[y][x];
    for (int i=y; i<y+dist; i++) {
        for (int j=x; j<x+dist; j++) {
            if (p[i][j] != d) return false;
        }
    }
    return true;
}

string compress(int y, int x, int dist) {
    string str = "";
    if (dist == 1 || isSameData(y, x, dist)) {
        str = p[y][x];
    } else {
        int newDist = dist / 2;
        str = "(";
        str += compress(y, x, newDist);
        str += compress(y, x+newDist, newDist);
        str += compress(y+newDist, x, newDist);
        str += compress(y+newDist, x+newDist, newDist);
        str += ")";
    }
    return str;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        string str;
        cin >> str;
        p.push_back(str);
    }
    
    cout << compress(0, 0, N) << endl;
    return 0;
}