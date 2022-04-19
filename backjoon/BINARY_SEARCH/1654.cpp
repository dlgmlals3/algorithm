#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int K, N;
vector<int> lans;
long long ans = 0;

int getLanCount(int mylen) {
    int cnt = 0;
    for (int lan : lans) {
        cnt += lan / mylen;
    }
    return cnt;
}

void binarySearch() {
    long long l = 1; 
    long long r = pow(2, 31)-1;
    ans = l;
    while (l <= r) {
        long long mid = (l + r) / 2;
        long long cnt = getLanCount(mid);
        if (cnt >= N) {
            ans = max(ans, mid);        
            l = mid + 1;
        } else {
            r = mid - 1;            
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> K >> N;
    int maxLanLen = -1; 

    for (int i=0; i<K; i++) {
        int num;
        cin >> num;
        lans.push_back(num);
        if (maxLanLen == -1 || maxLanLen < num) {
            maxLanLen = num;
        }
    } 

    // 전부다할 경우 복잡도는 10000 * (2의31승 -1) = 10000 * 20억 > 100만
    // 10000 * 100
    // for (long long i=1; i<=maxLanLen; i++) {
    //     if (N <= getLanCount(i)) {
    //         ans = max(ans, i);
    //     }
    // }

    binarySearch();
    cout << ans << '\n';
    return 0;
}