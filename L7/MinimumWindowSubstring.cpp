#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";
    
    vector<int> t_freq(128, 0);
    for (char c : t) {
        t_freq[c]++;
    }
    
    int required_matches = 0;
    for (int count : t_freq) {
        if (count > 0) {
            required_matches++;
        }
    }
    
    vector<int> window_freq(128, 0);
    int left = 0, right = 0;
    int current_matches = 0;
    int min_len = INT_MAX;
    int start_idx = 0;
    
    while (right < s.length()) {
        char c = s[right];
        if (t_freq[c] > 0) {
            window_freq[c]++;
            if (window_freq[c] == t_freq[c]) {
                current_matches++;
            }
        }
        
        while (current_matches == required_matches) {
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                start_idx = left;
            }
            
            char left_char = s[left];
            if (t_freq[left_char] > 0) {
                if (window_freq[left_char] == t_freq[left_char]) {
                    current_matches--;
                }
                window_freq[left_char]--;
            }
            left++;
        }
        right++;
    }
    
    return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
}

int main() {
    string s, t;
    if (cin >> s >> t) {
        cout << minWindow(s, t) << endl;
    }
    return 0;
}
