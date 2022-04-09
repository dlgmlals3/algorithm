#include <iostream>
#include <queue>

using namespace std;

struct compare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first > b.first) {    
            return true;
        } else if (a.first == b.first && a.second > b.second) {
            return true;
        }
        return false;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> ans;

    int N;
    cin >> N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            if (!q.empty()) {
                auto k = q.top();
                ans.push_back(k.second);
                q.pop();
            } else {
                ans.push_back(0);
            }
        } else {
            q.push(make_pair(abs(num), num));
        }
    }
    for (auto a : ans) {
        cout << a << '\n';
    }
    return 0;
}