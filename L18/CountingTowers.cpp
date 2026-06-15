#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6;

long long dp[MAXN + 1][2];

void precompute() {
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= MAXN; ++i) {
        dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] + 4 * dp[i - 1][1]) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
        }
    }
    return 0;
}
