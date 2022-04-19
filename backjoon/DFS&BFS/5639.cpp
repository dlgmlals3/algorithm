#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void dfs(int s, int e) {
    if (s >= e) return;

    int num = v[s];
    int mid = s+1;
    for (; mid<e; mid++) {
        if (num < v[mid]) {
            break;
        }
    }
    dfs(s+1, mid);
    dfs(mid, e);
    cout << v[s] << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int num;

    while (cin >> num) {
        if (num == cin.eof()) break;
        v.push_back(num);        
    }
    dfs(0, v.size());

    return 0;
}
