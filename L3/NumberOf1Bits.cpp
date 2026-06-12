#include <iostream>
#include <cstdint>

using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    uint32_t n;
    if (cin >> n) {
        cout << hammingWeight(n) << endl;
    }
    return 0;
}
