#include <bits/stdc++.h>
using namespace std;

#define int long long

void ab_d() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

void solve(int n, int m) {
    vector<int> operations;

    for (int i = 62; i >= 0; --i) {
        int y = (1LL << i) - 1;

        if ((n & y) == m) {
            operations.push_back(n);
            operations.push_back(m);
            break;
        }

        if ((n & (1LL << i)) == 0 && ((m & (1LL << i)) > 0)) {
            n ^= y;
            operations.push_back(n);
        }
    }

    if (operations.size() == 0) {
        cout << -1 << endl;
    } else {
        cout << operations.size() / 2 << endl;
        for (int op : operations) {
            cout << op << " ";
        }
        cout << endl;
    }
}

int32_t main() {
    ab_d();

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        solve(n, m);
    }

    return 0;
}
