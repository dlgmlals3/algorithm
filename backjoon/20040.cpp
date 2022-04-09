#include <iostream>
#include <vector>

using namespace std;

int N, M;
int parent[500001];
int level[500001];

int Find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = Find(parent[a]);
}

bool Union(int p, int c) {
    p = Find(p);
    c = Find(c);

    if (p == c) return false;

    if (level[p] < level[c]) {
        swap(p, c);
    }
    parent[c] = p; 
    if (level[p] == level[c]) {
        level[p] = level[c] + 1;
    }   
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for (int i=0; i<N; i++) parent[i] = i;
    
    bool isCycle = false;
    for (int i=1; i<=M; i++) {
        int a, b;
        cin >> a >> b;       
        if (!Union(a, b)) {
            isCycle = true;
            cout << i << '\n';
            break;
        }
    }
    if (!isCycle) {
        cout << "0" << '\n';
    }
    return 0;
}