#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, K;

vector<int> nums(200001);
vector<int> S(200001);
map<int, int> cnt;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    for (int i=1; i<=N; i++) { 
        cin >> nums[i];
        S[i] = S[i-1] + nums[i];
    }

    long long ans = 0;
    cnt[0] = 1;
    for (int i=1; i<=N; i++) { 
        ans += cnt[S[i]-K];
        cnt[S[i]]++;
    }
    for (int i=0; i<=N; i++) {
        cout << cnt[i] << " ";
    }cout << endl;
    cout << ans << '\n';

    return 0;
}