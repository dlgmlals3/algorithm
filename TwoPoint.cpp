#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void TwoPoints_1() {
    int N, X;
    vector<int> v;
    cin >> N;    
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    cin >> X;

    int ans = 0;
    int start = 0;
    int end = N-1;
    sort(v.begin(), v.end()); // 정렬 함.

    while (start < end) {
        if (v[start] + v[end] == X) {
            start++; end--; ans++;
        } else if (v[start] + v[end] < X) {
            start++;
        } else {
            end--;
        }
    }
    cout << ans << '\n';
}

void TwoPoints_2() {
    int N, S;
    vector<int> v;
    cin >> N >> S;
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    // 정렬 안함
    int s = 0;
    int e = 0;
    int ans = INT_MAX;
    long long sum = v[0];

    while (s <= e && e < N) {         
        if (sum < S) {
            sum += v[++e];
        } else { 
            // 정답의 범위
            ans = min(ans, e-s+1);   
            sum -= v[s++];
        }
    }
    if (ans == INT_MAX) {
        ans = 0;
    }
    cout << ans << '\n';
}

int main(void) {
    //TwoPoints_1();
    //TwoPoints_2();
    return 0;
}