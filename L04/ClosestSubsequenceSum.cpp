#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void getSubsetSums(const vector<int>& nums, int start, int end, vector<int>& sums) {
    sums.push_back(0);
    for (int i = start; i < end; ++i) {
        int val = nums[i];
        int n = sums.size();
        for (int j = 0; j < n; ++j) {
            sums.push_back(sums[j] + val);
        }
    }
}

int minAbsDifference(vector<int>& nums, int goal) {
    int n = nums.size();
    vector<int> left_sums, right_sums;
    getSubsetSums(nums, 0, n / 2, left_sums);
    getSubsetSums(nums, n / 2, n, right_sums);
    
    sort(right_sums.begin(), right_sums.end());
    
    int ans = abs(goal);
    for (int x : left_sums) {
        int target = goal - x;
        auto it = lower_bound(right_sums.begin(), right_sums.end(), target);
        if (it != right_sums.end()) {
            ans = min(ans, abs(goal - (x + *it)));
        }
        if (it != right_sums.begin()) {
            ans = min(ans, abs(goal - (x + *(--it))));
        }
    }
    return ans;
}

int main() {
    int n, goal;
    if (cin >> n >> goal) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << minAbsDifference(nums, goal) << endl;
    }
    return 0;
}
