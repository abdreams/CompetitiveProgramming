// semper fi //
// abdreams //

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define setbits(x) __builtin_popcountll(x)
#define mod 1000000007
#define inf 1e18
#define w(x) int x; cin >> x; while (x--)


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void ab_d() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int solveRecursion(int i, int lift, vector<int>& a, vector<int>& b, vector<vector<int>>& dp, int c) {
    if (i == 0) {
        if (lift)
            return dp[i][lift] = c;
        else
            return dp[i][lift] = 0;
    }

    if (dp[i][lift] != -1) {
        return dp[i][lift];
    }

    int ans = 1e9;
    if (lift) {
        ans = solveRecursion(i - 1, 0, a, b, dp, c) + b[i - 1] + c;
        ans = min(ans, solveRecursion(i - 1, 1, a, b, dp, c) + b[i - 1]);
    }
    else {
        ans = solveRecursion(i - 1, 0, a, b, dp, c) + a[i - 1];
        ans = min(ans, solveRecursion(i - 1, 1, a, b, dp, c) + a[i - 1]);
    }

    return dp[i][lift] = ans;
}

int32_t main() {
    ab_d();

    int n, c;
    cin >> n >> c;

    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    vector<vector<int>> dp(n, vector<int>(2, -1));

    solveRecursion(n - 1, 0, a, b, dp, c);
    solveRecursion(n - 1, 1, a, b, dp, c);

    for (int i = 0; i < n; i++) {
        cout << min(dp[i][0], dp[i][1]) << " ";
    }
    cout << endl;

    return 0;
}
