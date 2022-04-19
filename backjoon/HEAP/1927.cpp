#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> min_q;
 
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            if (!min_q.empty()) {
                cout << min_q.top() << '\n';
                min_q.pop();
            } else {
                cout <<'0' << '\n';
            }
        } else {
            min_q.push(num);
        }
    }
    return 0;
}