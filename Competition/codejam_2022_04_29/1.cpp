#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int T;
int ans = -1;
int n;
vector<bool> check(9, false);
string bob, alice;

void go(string aliceCards, int bobCards) {
    if (atoi(aliceCards.c_str()) < bobCards) {
        //cout << "bobCards : " << bobCards << endl;
        ans = max(ans, atoi(aliceCards.c_str()));
    }

    for (int i=0; i<n; i++) {
        if (check[i]) continue;
        check[i] = true;
        go(aliceCards + alice[i], bobCards);
        check[i] = false;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;
    while (T--) {
        fill(check.begin(), check.end(), false);
        ans = -1;
        cin >> n >> bob >> alice;
        
        int bob_f = atoi(bob.c_str());
        reverse(bob.begin(), bob.end());
        int bob_m = min(bob_f, atoi(bob.c_str()));
        
        for (int i=0; i<n; i++) {
            check[i] = true;            
            go((string)"" + alice[i], bob_m);
            check[i] = false;
        }
        cout << ans << '\n';
    }
    return 0;
}