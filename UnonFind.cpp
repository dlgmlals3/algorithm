#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000001
int parent[MAX];
int ranks[MAX];

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

    for (int i=1; i<MAX; i++) parent[i] = i;

    // test
    Union(1, 2);
    Union(2, 3);
    Union(3, 4);
    if (Find(1) == Find(4)) {
        cout << "Same Group " << Find(1) << '\n';
    } else {
        cout << "differ Group " << Find(1) << '\n';
    }
    return 0;
}