#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canProduce(const vector<long long>& k, long long t, long long time) {
    long long products = 0;
    for (long long machine_time : k) {
        products += time / machine_time;
        if (products >= t) {
            return true;
        }
    }
    return products >= t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long t;
    if (cin >> n >> t) {
        vector<long long> k(n);
        long long min_val = 2e9;
        for (int i = 0; i < n; ++i) {
            cin >> k[i];
            min_val = min(min_val, k[i]);
        }
        long long low = 1;
        long long high = min_val * t;
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canProduce(k, t, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
