#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int N, C;
int ans = 0;

void dfs(int s, int e, long long sum, vector<long long> &halfv) {
    if (s > e) {
        halfv.push_back(sum);
        return;
    }
    dfs(s+1, e, sum + v[s], halfv); // 선택하는 경우
    dfs(s+1, e, sum, halfv); // 선택하지 않는 경우
}

int main(void) {
    cin >> N >> C;
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    vector<long long> v1;
    vector<long long> v2;
    // 가지고 있는 물건의 경우의 수가 너무많아서 (1의 30승)
    // 가지고 있는 물건의 반반 잘라서 
    // 가방에 들어갈수 있는 모든 경우의 수 무게의 배열을 만듬
    dfs(0, N/2, 0, v1);
    dfs(N/2+1, N-1, 0, v2);

    sort(v2.begin(), v2.end());
    
    long long ans = 0;
    for (long long w : v1) {
        ans += upper_bound(v2.begin(), v2.end(), C-w) - v2.begin();
    }
    cout << ans << '\n';
    return 0;
}