#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, X;
vector<int> v;

int main(void) {
    cin >> N;
    int num;
    for (int i=0; i<N; i++) {
        cin >> num;
        v.push_back(num);
    }
    cin >> X;
    int start = 0;
    int end = N-1;    
    int ans = 0;

    sort(v.begin(), v.end());
    while (start < end) {
        if (v[start] + v[end] == X) {
            start++;
            end--;
            ans++;
        } else if (v[start] + v[end] < X) {
            start++;
        } else {
            end--;
        }
    }
    cout << ans << '\n';
    return 0;
}