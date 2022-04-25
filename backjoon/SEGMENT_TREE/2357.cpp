#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#define MAXNODE 100001
using namespace std;

vector<int> nums(MAXNODE, 0);

int N, M;

int h = ceil(log2(MAXNODE));
int TREE_SIZE = (1 << h+1);
vector<int> minTree(TREE_SIZE, INT_MAX);
vector<int> maxTree(TREE_SIZE, 0);

void segment_init(int node, int s, int e) {
    if (s == e) {
        maxTree[node] = nums[s];
        minTree[node] = nums[s];
        return;
    }
    segment_init(node*2, s, (s+e)/2);
    segment_init(node*2+1, (s+e)/2+1, e);
    minTree[node] = min(minTree[node*2], minTree[node*2+1]);
    maxTree[node] = max(maxTree[node*2], maxTree[node*2+1]);
}

int segment_min_travase(int node, int s, int e, int q_s, int q_e) {
    if (q_e < s || e < q_s) return -1;
    if (q_s <= s && e <= q_e) return minTree[node];
    
    int s1 = segment_min_travase(node*2, s, (s+e)/2, q_s, q_e);
    int s2 = segment_min_travase(node*2+1, (s+e)/2+1, e, q_s, q_e);
    if (s1 == -1) return s2;
    if (s2 == -1) return s1;
    return min(s1, s2);
}

int segment_max_travase(int node, int s, int e, int q_s, int q_e) {
    if (q_e < s || e < q_s) return -1;
    if (q_s <= s && e <= q_e) return maxTree[node];
    
    int s1 = segment_max_travase(node*2, s, (s+e)/2, q_s, q_e);
    int s2 = segment_max_travase(node*2+1, (s+e)/2+1, e, q_s, q_e);
    if (s1 == -1) return s2;
    if (s2 == -1) return s1;
    return max(s1, s2);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;

    for (int i=1; i<=N; i++) {
        cin >> nums[i];
    }   

    segment_init(1, 1, N);
    for (int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        int minSeg = segment_min_travase(1, 1, N, u, v);
        int maxSeg = segment_max_travase(1, 1, N, u, v);
        cout << minSeg << ' ' << maxSeg << '\n';
    }
    return 0;
}