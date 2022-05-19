#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> nums(100001);
vector<int> S(100001);
map<int, int> cnt;

int N, M;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i=1; i<=N; i++) {
        cin >> nums[i];
        S[i] = S[i-1] + nums[i];
    }    

    for (int i=1; i<=N; i++) {
        cnt[i]     
    }

    return 0;
}