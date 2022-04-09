#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, M, K;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    cin >> K;
    
    map<int, bool> m;
    vector<int> caught;
    bool dangerous = false;

    for (int i=0; i<v.size(); i++) {
        if (v[i] == K) {
            for (auto it=m.begin(); it != m.end(); ++it) {
                if (it->second == true) {
                    caught.push_back(it->first);
                }
            }
            dangerous = true;
        } else if (v[i] == -K) {
            dangerous = false;
            m.clear();
        } else {
            if (v[i] > 0) {
                m[v[i]] = true;
            } else {
                m[v[i] * -1] = false;
            }
            if (dangerous && v[i] > 0) {
                caught.push_back(v[i]);
            }
        }
    }
    sort(caught.begin(), caught.end());
    auto last = unique(caught.begin(), caught.end()); // start index ~ end index remove
    caught.erase(last, caught.end());

    if (caught.size() > 1) {
        for (auto i : caught) {
            cout << i << " ";
        } cout << '\n';
    } else {
        cout << "-1" << '\n';
    }

	return 0;
}