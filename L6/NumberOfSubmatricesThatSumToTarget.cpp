#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    if (rows == 0) return 0;
    int cols = matrix[0].size();
    
    for (int r = 0; r < rows; ++r) {
        for (int c = 1; c < cols; ++c) {
            matrix[r][c] += matrix[r][c - 1];
        }
    }
    
    int count = 0;
    unordered_map<int, int> sum_counts;
    
    for (int c1 = 0; c1 < cols; ++c1) {
        for (int c2 = c1; c2 < cols; ++c2) {
            sum_counts.clear();
            sum_counts[0] = 1;
            int current_sum = 0;
            for (int r = 0; r < rows; ++r) {
                int val = matrix[r][c2] - (c1 > 0 ? matrix[r][c1 - 1] : 0);
                current_sum += val;
                if (sum_counts.count(current_sum - target)) {
                    count += sum_counts[current_sum - target];
                }
                sum_counts[current_sum]++;
            }
        }
    }
    return count;
}

int main() {
    int rows, cols, target;
    if (cin >> rows >> cols) {
        vector<vector<int>> matrix(rows, vector<int>(cols));
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                cin >> matrix[r][c];
            }
        }
        cin >> target;
        cout << numSubmatrixSumTarget(matrix, target) << endl;
    }
    return 0;
}
