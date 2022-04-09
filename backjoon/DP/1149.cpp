#include <iostream>
#include <algorithm>

using namespace std;

int N;

int dp[1001][3];
// n : 1 ~ 10000
// Sn = An + 3 // 등차
// Sn = An * 3 // 등비
// S1 = A1 + 3;  ( )
int main(void) {
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
    }
    for (int i=2; i<=N; i++) {
        dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
    }
    // dp[N][0] dp[N][1] dp[N][2]
    int ans = min(min(dp[N][0], dp[N][1]), dp[N][2]);
    cout << ans << endl;
    return 0;
}