#include <iostream>
#include <vector>
using namespace std;

int N, M, K;

long long getSum(vector<long long> &tree, int index) {
    long long sum = 0;
    while (index > 0) {
        sum += tree[index];
        index -= index & -index;
    }
    return sum;
}

void update(vector<long long> &tree, int index, long long diff) {
    while (index < tree.size()) {
        tree[index] += diff;
        index += index & -index;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M >> K;
    vector<long long> arr(N+1);
    vector<long long> tree(N+1);
    vector<long long> ans;

    for (int i=1; i<=N; i++) {
        cin >> arr[i];
        update(tree, i, arr[i]);
    }

    for (int i=1; i<=M+K; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            long long diff = c - arr[b];
            arr[b] = c;
            update(tree, b, diff);
        } else {
            
            long long sum = getSum(tree, c) - getSum(tree, b-1);
            ans.push_back(sum);
        }
    }
    for (auto i : ans) {
        cout << i << '\n';
    }
    return 0;
}