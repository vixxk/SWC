#include <iostream>

using namespace std;

long long divisorsSum(long long x) {
    long long sum = 0;
    for (long long i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            sum += i;
            if (i * i != x) {
                sum += x / i;
            }
        }
    }
    return sum;
}

bool isDeficient(long long x) {
    return divisorsSum(x) < 2 * x;
}

int main() {
    long long x;
    if (cin >> x) {
        if (isDeficient(x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
