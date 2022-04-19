// sorting
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <map>
#include <climits>
#include <math.h>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second > b.second) return true;
    if (a.second == b.second && a.first < b.first) {
        return true;
    }
    return false;
}   

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<int> v;
    
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    map<int, int> m;
    for (int i=0; i<N; i++) {
        m[v[i]]++;
    }
    vector<pair<int, int>> cntV(m.begin(), m.end());
    sort(cntV.begin(), cntV.end(), compare);

    int sum = 0;
    int maxValue = -INT_MAX;
    int minValue = INT_MAX;

    for (int i=0; i<N; i++) {
        sum += v[i];
        maxValue = max(maxValue, v[i]);
        minValue = min(minValue, v[i]);
    }
    int average = round((float)sum / N);

    int mid = v[N/2];
    int range = maxValue - minValue;
    int count = cntV[0].first;
    if (cntV[0].second == cntV[1].second) {
        count = cntV[1].first;
    }
    cout << average << '\n';
    cout << mid << '\n';
    cout << count << '\n';
    cout << range << '\n';

    return 0;
}