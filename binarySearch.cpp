#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> nums = {10 ,9, 8, 7, 5, 5, 6, 4, 2, 3, 1};

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
    sort(nums.begin(), nums.end());
    int num = 5;

    auto lower_itr = lower_bound(nums.begin(), nums.end() , num);
    auto upper_itr = upper_bound(nums.begin(), nums.end(), num);

    if (binarySearch(num)) {
        int sameCount = upper_itr - lower_itr;
        cout << num << " is exist same " << sameCount << '\n';
    } else {
        cout << num << " is not exist" << '\n';
    }

    return 0;
}