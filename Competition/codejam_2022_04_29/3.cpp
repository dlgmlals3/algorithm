#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;



bool go(vector<pair<int, int>> &v, vector<int> &cnt) {
    for (int i=N-1, start=cnt.size()-1; i>=0; i--, start--) {
        while (start >= 0) {
            if (cnt[start] != 0) {
                start--;
            } else {
                break;
            }
        }
        if (start < 0) return false;
        
        pair<int, int> p = v[i];
        
        for (int j=0; j<p.second; j++) {
            if (start-j*2 >= cnt.size()) {
                return false;
            } 
            cnt[start-j*2] = p.first;
        }
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        vector<pair<int, int>> v;
        cin >> N;
        int cntSum = 0;
        for (int i=0; i<N; i++) {
            int num;
            cin >> num;
            v.push_back(make_pair(i+1, num));
            cntSum += num;
        }
        sort(v.begin(), v.end());
        
        bool findAns = false;
        vector<int> cnt(cntSum, 0);
        do {
            fill(cnt.begin(), cnt.end(), 0);
            if (go(v, cnt)) {
                findAns = true;
                break;
            }
        } while(next_permutation(v.begin(), v.end()));
        
        if (findAns) {
            for (int i=0; i<cnt.size(); i++) {
                cout << cnt[i] << " ";
            } cout << endl;
        } else {
            cout << "IMPOSSIBLE" << '\n';
        }
    }
    
    return 0;
}