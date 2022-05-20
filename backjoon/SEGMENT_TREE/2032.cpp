#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;
void segment_init(vector<long long> &tree, vector<long long> &an, int node, int s, int e) {
    if (s == e) {
        tree[node] = an[s];
        return;
    }
    segment_init(tree, an, 2*node, s, (s+e)/2);
    segment_init(tree, an, 2*node+1, (s+e)/2+1, e);
    tree[node] = tree[2*node] + tree[2*node+1];
}

void segment_update(vector<long long> &tree, vector<long long> &an, int node, int s, int e, int index, long long diff) {
    if (index < s || index > e) return;
    tree[node] += diff;
    
    if (s != e) {
        segment_update(tree, an, 2*node, s, (s+e)/2, index, diff);
        segment_update(tree, an, 2*node+1, (s+e)/2+1, e, index, diff);
    }
}

long long segment_traverse(vector<long long> &tree, vector<long long> &an, int node, int s, int e, int s_sec, int e_sec) {
    if (e_sec < s || e < s_sec ) return -1;
    if (s_sec <= s && e <= e_sec) return tree[node];

    long long s1 = segment_traverse(tree, an, 2*node, s, (s+e)/2, s_sec, e_sec);
    long long s2 = segment_traverse(tree, an, 2*node+1, (s+e)/2+1, e, s_sec, e_sec);
    if (s1 == -1) return s2;
    if (s2 == -1) return s1;
    return s1 + s2;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    int h = ceil(log2(N));
    int treeSize = (1 << h+1);
    vector<long long> an(N+1);

    vector<long long> tree(treeSize);
    for (int i=1; i<=N; i++) {
        cin >> an[i];
    }
    segment_init(tree, an, 1, 1, N);
    vector<long long> ans;
    for (int i=0; i<M+K; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            long long diff = c - an[b];
            an[b] = c;
            segment_update(tree, an, 1, 1, N, b, diff);
        } else {
            ans.push_back(segment_traverse(tree, an, 1, 1, N, b, c));
        }
    }
    for (auto i : ans) {
        cout << i << '\n';
    }
    return 0;
}