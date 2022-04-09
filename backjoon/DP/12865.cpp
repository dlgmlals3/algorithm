#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int w[101];
int v[101];
int dp[101][100001]; // 101 * 십만 * 4 //

int main(void) {
    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=K; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - w[i] >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    cout << dp[N][K] << endl;
    return 0;
}