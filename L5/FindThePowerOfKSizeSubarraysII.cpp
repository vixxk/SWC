#include <iostream>
#include <vector>

using namespace std;

vector<int> resultsArray(vector<int>& nums, int k) {
    int n = nums.size();
    if (k == 1) return nums;
    vector<int> results(n - k + 1, -1);
    int consecutive_len = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i] - nums[i - 1] == 1) {
            consecutive_len++;
        } else {
            consecutive_len = 1;
        }
        if (i >= k - 1) {
            if (consecutive_len >= k) {
                results[i - k + 1] = nums[i];
            }
        }
    }
    return results;
}

int main() {
    int n, k;
    if (cin >> n >> k) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        vector<int> res = resultsArray(nums, k);
        for (size_t i = 0; i < res.size(); ++i) {
            cout << res[i] << (i == res.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}
