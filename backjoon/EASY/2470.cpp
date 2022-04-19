#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N;
vector<int> v;

int main(void) {
    cin >> N;
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    
    vector<int> ch(2, 0);
    int start = 0;
    int end = N-1;
    long long closedZero = 2000000001;

    while (start < end) {
        if (closedZero > abs(v[start] + v[end])) {
            closedZero = abs(v[start] + v[end]);
            ch[0] = v[start];
            ch[1] = v[end];
        }
        if (v[start] + v[end] == 0) {
            ch[0] = v[start];
            ch[1] = v[end];
            break;
        } else if (v[start] + v[end] < 0) {
            start++;
        } else {
            end--;
        }
    }
    sort(ch.begin(), ch.end());
    cout << ch[0] << " " << ch[1] << '\n';
    return 0;
}

