
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;
int N, M;

void segmentInit(vector<int> &tree, vector<int> &arr, int node, int s, int e) {
    if (s == e) {
        tree[node] = arr[s];
    } else {
        segmentInit(tree, arr, node*2, s, (s+e)/2);
        segmentInit(tree, arr, node*2+1, (s+e)/2+1, e);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
}

int query(vector<int> &tree, int node, int s, int e, int s1, int e1) {
    if (e1 < s || e < s1) return -1;
    if (s1 <= s && e <= e1) return tree[node];

    int lv = query(tree, node*2, s, (s+e)/2, s1, e1);
    int rv = query(tree, node*2+1, (s+e)/2+1, e, s1, e1);
    
    if (lv == -1) return rv;
    if (rv == -1) return lv;
    return min(lv, rv);    
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    vector<int> arr(100001);
    
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    int treeHeight = ceil(log2(N));
    int treeSize = (1 << (treeHeight+1));
    vector<int> tree(treeSize);
    
    segmentInit(tree, arr, 1, 0, N-1);
    for (int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;   
        cout << query(tree, 1, 0, N-1, u-1, v-1) << '\n';
    }
    return 0;
}