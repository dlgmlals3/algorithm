#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<int> trees;

long long getRemainTree(long long len) {
    long long haveTree = 0;
    for (int tree : trees) {
        if (tree - len > 0) {
            haveTree += tree - len;
        }
    }
    return haveTree;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;    

    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        trees.push_back(num);
    }

    int l = 0;
    int r = 1000000000;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        long long remain = getRemainTree(mid);
        
        if (remain >= M) {
            l = mid + 1;
            if (ans == -1 || ans < mid) {
                ans = mid;
            }
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}