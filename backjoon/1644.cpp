#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> aristoche(int n) {
    int target = n;
    vector<bool> isSosu(target, true);
    isSosu[0] = false;
    isSosu[1] = false;
    for (int i=2; i<=target; i++) {
        for (int j=i*i; j<=target; j+=i) {
            isSosu[j] = false;
        }
    }
    vector<int> v;
    for (int i=0; i<=target; i++) {
        if (isSosu[i]) {
            v.push_back(i);
        }
    }
    return v;
}

int main(void) {
    cin >> N;
    vector<int> arr = aristoche(4000000);
    int s = 0;
    int e = 0;
    
    int sum = arr[s];
    int ans = 0;
    while(s <= e && e < arr.size()) {
        if (sum > N) {
            sum -= arr[s++];
        } else {
            if (sum == N) ans++;
            sum += arr[++e];
        }
    }
    cout << ans << '\n';
    return 0;
}