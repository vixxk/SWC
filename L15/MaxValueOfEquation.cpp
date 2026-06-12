#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

using namespace std;

int findMaxValueOfEquation(const vector<vector<int>>& points, int k) {
    deque<pair<int, int>> dq;
    int max_val = INT_MIN;
    for (const auto& point : points) {
        int x = point[0];
        int y = point[1];
        while (!dq.empty() && x - dq.front().second > k) {
            dq.pop_front();
        }
        if (!dq.empty()) {
            max_val = max(max_val, dq.front().first + y + x);
        }
        while (!dq.empty() && dq.back().first <= y - x) {
            dq.pop_back();
        }
        dq.push_back({y - x, x});
    }
    return max_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    if (cin >> n >> k) {
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            cin >> points[i][0] >> points[i][1];
        }
        cout << findMaxValueOfEquation(points, k) << "\n";
    }
    return 0;
}
