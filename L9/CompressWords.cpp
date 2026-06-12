#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string compressWords(const vector<string>& words) {
    if (words.empty()) return "";
    string ans = words[0];
    for (size_t i = 1; i < words.size(); ++i) {
        const string& s = words[i];
        int len = min(ans.length(), s.length());
        string suff = ans.substr(ans.length() - len);
        string temp = s + '#' + suff;
        int temp_len = temp.length();
        vector<int> pi(temp_len, 0);
        for (int j = 1; j < temp_len; ++j) {
            int k = pi[j - 1];
            while (k > 0 && temp[j] != temp[k]) {
                k = pi[k - 1];
            }
            if (temp[j] == temp[k]) {
                k++;
            }
            pi[j] = k;
        }
        int overlap = pi.back();
        ans += s.substr(overlap);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (cin >> n) {
        vector<string> words(n);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
        }
        cout << compressWords(words) << "\n";
    }
    return 0;
}
