#include <iostream>
#include <vector>
#include <string>

using namespace std;

int C[31][31];

void precompute() {
    for (int i = 0; i <= 30; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

string kthSmallestPath(int row, int col, int k) {
    precompute();
    string result = "";
    int h = col;
    int v = row;
    int total_steps = h + v;
    for (int i = 0; i < total_steps; ++i) {
        if (h > 0) {
            int ways = C[h - 1 + v][v];
            if (k <= ways) {
                result += 'H';
                h--;
            } else {
                result += 'V';
                k -= ways;
                v--;
            }
        } else {
            result += 'V';
            v--;
        }
    }
    return result;
}

int main() {
    int row, col, k;
    if (cin >> row >> col >> k) {
        cout << kthSmallestPath(row, col, k) << endl;
    }
    return 0;
}
