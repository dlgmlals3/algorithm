#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> nums;

bool binarySearch(int num) {
    int l = 0;
    int r = nums.size()-1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] <= num) {
            l = mid + 1;
            if (num == nums[mid]) {
                return true;
            }
        } else {
            r = mid - 1;
        }
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;

    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }   
    sort(nums.begin(), nums.end());

    cin >> M;
    for (int i=0; i<M; i++) {
        int num;
        cin >> num;

        if (binarySearch(num)) {
            cout << "1" << '\n';
        } else {
            cout << "0" << '\n';
        }
    }
    return 0;
}