#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second < b.second) return true;
    return false;
}

int main(void) {
    map<int, int> m; // pair
    m[3] = 1;
    m[2] = 4;
    m[1] = 2;
    m[0] = 6;
    m[-10] = 3;
    m[-20] = 5;
    for (auto i : m) {
        cout << i.first << " " << i.second << endl;
    }

    // key char
    map<char, int> m2;
    m2['a'] = 1;
    m2['b'] = 4;
    m2['d'] = 2;
    m2['c'] = 6;
    m2['k'] = 3;
    for (auto i : m2) {
        cout << i.first << " " << i.second << endl;
    }
    cout << m2['k'] << endl;

    // key 정렬 map --> vector로 변경
    map<int, int> m3;
    m3[3] = 1;
    m3[2] = 4;
    m3[1] = 2;
    m3[0] = 6;
    vector<pair<int, int>> vec( m3.begin(), m3.end() );
    sort(vec.begin(), vec.end(), cmp);
    for (auto i : vec) {
        cout << i.first << " " << i.second  << endl;
    }
    return 0;
}
