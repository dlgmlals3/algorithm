#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#define MAXV 100001

using namespace std;

int h = ceil(log2(MAXV));
int tree_size = (1 << h+1);
vector<int> an(MAXV);
vector<int> minTree(tree_size);

void segment_init(int node, int s, int e) {
    if (s == e) {
        minTree[node] = an[s];
        return;
    }
    segment_init(2*node, s, (s+e)/2);
    segment_init(2*node+1, (s+e)/2+1, e);
    minTree[node] = min(minTree[2*node], minTree[2*node+1]);
}

int segment_min_travase(int node, int s, int e, int q_s, int q_e) {
    if (q_e < s || e < q_s) return -1;
    if (q_s <= s && e <= q_e) return minTree[node];

    int a1 = segment_min_travase(2*node, s, (s+e)/2, q_s, q_e);
    int a2 = segment_min_travase(2*node+1, (s+e)/2+1, e, q_s, q_e);
    if (a1 == -1) return a2;
    if (a2 == -1) return a1;
    return min(a1, a2);
}

void segment_update(int node, int s, int e, int index, int value) {
    if (index < s || e < index) return;
    if (s == e) {
        minTree[node] = value;
        return;
    }
    segment_update(2*node, s, (s+e)/2, index, value);
    segment_update(2*node+1, (s+e)/2+1, e, index, value);
    minTree[node] = min(minTree[2*node], minTree[2*node+1]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, M;
    cin >> N;
    
    for (int i=1; i<=N; i++) {
        cin >> an[i];
    }

    segment_init(1, 1, N);

    cin >> M;

    for (int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            segment_update(1, 1, N, b, c);
        } else {
            cout << segment_min_travase(1, 1, N, b, c) << '\n';
        }        
    }
    
    return 0;
}