#include <iostream>
#include <algorithm>
using namespace std;

int N;
int s[100001];
int dp[100001];

int main(void) {   
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> s[i];
    }
    dp[1] = s[1];
    for (int i=2; i<=N; i++) {
        dp[i] = s[i];
        if (s[i] < dp[i-1]+s[i]) {
            dp[i] = dp[i-1]+s[i];
        }
    }
    int ans = -1001;
    for (int i=1; i<=N; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}