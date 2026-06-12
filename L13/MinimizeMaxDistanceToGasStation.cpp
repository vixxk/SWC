#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool isPossible(const vector<double>& stations, int k, double mid) {
    int count = 0;
    for (size_t i = 1; i < stations.size(); ++i) {
        count += (int)((stations[i] - stations[i - 1]) / mid);
    }
    return count <= k;
}

double minMaxGasDist(const vector<double>& stations, int k) {
    double low = 0;
    double high = stations.back() - stations.front();
    double precision = 1e-7;
    while (high - low > precision) {
        double mid = low + (high - low) / 2.0;
        if (isPossible(stations, k, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return low;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    if (cin >> n >> k) {
        vector<double> stations(n);
        for (int i = 0; i < n; ++i) {
            cin >> stations[i];
        }
        cout << fixed << setprecision(6) << minMaxGasDist(stations, k) << "\n";
    }
    return 0;
}
