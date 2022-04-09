#include <iostream>
#include <vector>

using namespace std;

long long cnt = 0;

void dfs(int H, int W) {
    if (H==0 && W==0) {
        cnt++;
        return;
    }
    if (H > 0) {
        dfs(H-1, W);
    }
    if (W > 0) {
        dfs(H+1, W-1);
    }
}

long long dp[61][31];

long long go(int H, int W) {
    if (W == 0) return 1;
    if (H == 0) return dp[H][W] = go(H+1, W-1);    
    if (dp[H][W] != 0) return dp[H][W]; // memoi zation;
    
    return dp[H][W] = go(H-1, W) + go(H+1, W-1);
}

int main(void) {
    int T;
    vector<long long> ans;
    while (true) {
        int N; 
        cin >> N;
        if (N == 0) break;
        // cnt = 0;
        ans.push_back(go(0, N));
    }

    for (auto i : ans) {
        cout << i << endl;
    }
    return 0;
}