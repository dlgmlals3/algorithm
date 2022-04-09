#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
vector<int> v;

int main(void) {
    cin >> N >> S;
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int s = 0;
    int e = 0;
    int ans = INT_MAX;

    long long sum = v[0];

    while (s <= e && e < N) {         
        if (sum < S) {
            sum += v[++e];
        } else {
            ans = min(ans, e-s+1);   
            sum -= v[s++];
        }
    }
    if (ans == INT_MAX) 
        ans = 0;
        
    cout << ans << '\n';
    return 0;
}