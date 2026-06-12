#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int maxAreaHistogram(const vector<int>& heights) {
    stack<int> s;
    int max_area = 0;
    int n = heights.size();
    for (int i = 0; i <= n; ++i) {
        int h = (i == n) ? 0 : heights[i];
        while (!s.empty() && h < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            max_area = max(max_area, height * width);
        }
        s.push(i);
    }
    return max_area;
}

int maximalRectangle(const vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) return 0;
    int r = mat.size();
    int c = mat[0].size();
    vector<int> heights(c, 0);
    int max_area = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (mat[i][j] == 1) {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        max_area = max(max_area, maxAreaHistogram(heights));
    }
    return max_area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c;
    if (cin >> r >> c) {
        vector<vector<int>> mat(r, vector<int>(c));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> mat[i][j];
            }
        }
        cout << maximalRectangle(mat) << "\n";
    }
    return 0;
}
