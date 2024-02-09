#include <bits/stdc++.h>
using namespace std;

#define int long long

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

bool areEquivalent(string s1, string s2) {
    int n = s1.length();
    
    if (s1 == s2) {
        return true;
    }

    if (n % 2 == 1) {
        return false;
    }

    string a1 = s1.substr(0, n / 2);
    string a2 = s1.substr(n / 2);

    string b1 = s2.substr(0, n / 2);
    string b2 = s2.substr(n / 2);

    return (areEquivalent(a1, b1) && areEquivalent(a2, b2)) || (areEquivalent(a1, b2) && areEquivalent(a2, b1));
}

int32_t main(){
    ab_d();

    int t;
    cin >> t;

    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        if (areEquivalent(s1, s2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
