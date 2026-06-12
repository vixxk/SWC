#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxDays(int n, int m, const vector<int>& a) {
    vector<int> counts(101, 0);
    for (int x : a) {
        if (x >= 1 && x <= 100) {
            counts[x]++;
        }
    }
    int low = 1, high = m;
    int ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int people_fed = 0;
        for (int count : counts) {
            people_fed += count / mid;
        }
        if (people_fed >= n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if (cin >> n >> m) {
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        cout << maxDays(n, m, a) << "\n";
    }
    return 0;
}
