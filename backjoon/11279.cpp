#include <iostream>
#include <queue>
using namespace std;

int N;

int main(void) {
    cin >> N;
    priority_queue<int> q;
    vector<int> ans;

    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            if (q.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(q.top());
                q.pop();
            }
        } else {
            q.push(num);
        }
    }
    
    for (auto a : ans) {
        cout << a << '\n';
    }

    return 0;
}