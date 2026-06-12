#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlace(const vector<int>& position, int m, int dist) {
    int count = 1;
    int last = position[0];
    for (size_t i = 1; i < position.size(); ++i) {
        if (position[i] - last >= dist) {
            count++;
            last = position[i];
            if (count >= m) {
                return true;
            }
        }
    }
    return false;
}

int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int low = 1;
    int high = position.back() - position[0];
    int ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlace(position, m, mid)) {
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
        vector<int> position(n);
        for (int i = 0; i < n; ++i) {
            cin >> position[i];
        }
        cout << maxDistance(position, m) << "\n";
    }
    return 0;
}
