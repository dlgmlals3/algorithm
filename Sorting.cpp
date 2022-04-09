#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void print(vector<int> &v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

void print2(vector<vector<int>> &v) {
    for (auto i : v) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << '\n';
    }
    cout << endl;
}
// pair 형태의 sorting
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
   if (a.first < b.first) return true;
   if (a.first == b.first && a.second < b.second) {
      return true;
   } 
   return false;
}

int main(void) {
    vector<int> v = {1,2,3,4,5};
    sort(v.begin(), v.end());
    print(v);
    sort(v.rbegin(), v.rend());
    print(v);
    reverse(v.begin(), v.end());
    print(v);

    vector<int> v2(5, 0);
    
    vector<vector<int>> v3(5, vector<int>(5, 1));
    print2(v3);
    fill(v3.begin(), v3.end(), vector<int>(5, -1));
    print2(v3);   

    vector<int> v4[5];
    for (int i=0; i<5; i++) {
        v4[i].push_back(1);
    }

    for (int i=0; i<5; i++) {
        v4[i].clear();
    }

    vector<pair<int, int>> v5;
    v5.push_back(make_pair(3, 1));
    v5.push_back(make_pair(1, 2));
    v5.push_back(make_pair(2, 1));
    v5.push_back(make_pair(5, 1));
    v5.push_back(make_pair(1, 1));
    sort(v5.begin(), v5.end(), compare);
    for (auto i : v5) {
        cout << i.first << " " << i.second << endl;
    }

      // 정렬 후 중복제거 
    vector<string> v7={"456", "123", "123", "999", "456", "357", "888", "999", "888"};
    sort(v7.begin(), v7.end());
    auto last = unique(v7.begin(), v7.end()); 
    v7.erase(last, v7.end());
    for (auto i : v7) cout << i << endl;

    vector<int> vv = {1,5,3,2,4};
    sort(vv.begin(), vv.end(), greater<int>());
    for (auto i : vv) cout << i << endl;
    
    sort(vv.begin(), vv.end(), less<int>());
    for (auto i : vv) cout << i << endl;
    return 0;
}