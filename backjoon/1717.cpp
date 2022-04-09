#include <iostream>
#include <algorithm>

using namespace std;

int parent[1000001];
int ranks[1000001];

int Find(int a) {
    if (parent[a] == a) 
        return a;
    return parent[a] = Find(parent[a]);
}

void Union(int p, int c) {
    p = Find(p);
    c = Find(c);
    if (ranks[p] < ranks[c]) {
        swap(p, c);
    }
    parent[c] = p;
    if (ranks[p] == ranks[c]) {
        ranks[p] = ranks[c] + 1;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;

    for (int i=1; i<=N; i++) parent[i] = i;

    for (int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            Union(b, c);
        } else {
            int g1 = Find(b);
            int g2 = Find(c);
            if (g1 == g2) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}