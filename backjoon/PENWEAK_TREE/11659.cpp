#include <iostream>
#include <vector>
using namespace std;

vector<int> nums(100001);
vector<int> nu(100001);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    
    for (int i=1; i<=N; i++) {
        cin >> nums[i];
        nu[i] = nums[i] + nu[i-1];
    }
    for (int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        cout << nu[v] - nu[u-1] << '\n';
    }
    return 0;
}