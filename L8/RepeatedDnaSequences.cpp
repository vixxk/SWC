#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<string> seen;
    unordered_set<string> repeated;
    if (s.length() < 10) return {};
    
    for (int i = 0; i <= (int)s.length() - 10; ++i) {
        string sub = s.substr(i, 10);
        if (seen.count(sub)) {
            repeated.insert(sub);
        } else {
            seen.insert(sub);
        }
    }
    return vector<string>(repeated.begin(), repeated.end());
}

int main() {
    string s;
    if (cin >> s) {
        vector<string> res = findRepeatedDnaSequences(s);
        for (const string& seq : res) {
            cout << seq << endl;
        }
    }
    return 0;
}
