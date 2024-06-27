#include <bits/stdc++.h>
using namespace std;

bool isValid(const string& s, const string& substr) {
    int diffCount = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != substr[i % substr.length()]) {
            if (++diffCount > 1) {
                return false;
            }
        }
    }
    return true;
}

int shortestRepeatingSubstringLength(const string& s) {
    int n = s.length();
    int shortestLength = n;

    for (int len = 1; len <= n; ++len) {
        if (n % len != 0) {
            continue; 
        }

        string substr = s.substr(0, len);
        if (isValid(s, substr)) {
            shortestLength = min(shortestLength, len);
        }

        substr = s.substr(n - len, len);
        if (isValid(s, substr)) {
            shortestLength = min(shortestLength, len);
        }
    }

    return shortestLength;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << shortestRepeatingSubstringLength(s) << endl;
    }

    return 0;
}
