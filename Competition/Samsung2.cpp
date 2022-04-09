#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
static int debug = 0;

int N = 10, K = 2;
vector<int> v = {12, 8, 22, 6, 34, 7, 35, 10, 41, 21};
long long ans = 0;

pair<long long, int> getCount(long long mid) {
    int cnt = 0;
    int minV = v[0];
    int maxV = v[0];
    long long sum = 0;
    for (int i=1; i<v.size(); i++) {
        minV = min(minV, v[i]);
        maxV = max(maxV, v[i]);
        if (minV != maxV && maxV - minV >= mid) {
            cnt++;
            sum += (maxV - minV);
            //cout << " max : " << maxV << " " << minV << endl;
            maxV = 0;
            minV = INT_MAX;
        }
    }
    if (maxV != 0 && minV != INT_MAX) {
        sum += (maxV - minV);
        cnt++;
    }
    return make_pair(sum, cnt);
}

int main(void) {
    reverse(v.begin(), v.end());
    long long ans = 0;
    long long l = 0;
    long long r = 10000 * 5000;
    
    long long prev = -1;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (prev == mid) break;
        auto item = getCount(mid);
    
        //cout << "l " << l << " r : " << r << " mid : " << mid << " sum : " << item.first << " cnt : " << item.second << endl;
        
        if (item.second >= K) {
            if (item.second == K) {
                ans = max(ans, item.first);                
            }
            l = mid - 1;
        } else {
            r = mid + 1;
        }
        prev = mid;
    }
    cout << ans << '\n';
    return 0;
}