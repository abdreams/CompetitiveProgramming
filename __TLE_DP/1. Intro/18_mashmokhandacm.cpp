// semper fi //
// abdreams //
// https://codeforces.com/contest/414/problem/B

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define w(x)            int x; cin>>x; while(x--)

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

int n, k;
vector<vector<int>>dp;

int solve(int cur, int len) {
    if (len == k) {
        return 1;
    }

    if(dp[cur][len]!=-1) return dp[cur][len];

    int ways = 0;
    
    for (int i = cur; i <= n; i+=cur) {
        if (i % cur == 0) {
            ways = (ways + solve(i, len + 1)) % mod;
        }
    }
    return dp[cur][len]= ways;
}

int32_t main() {
ab_d();
    cin >> n >> k;
    int ans = 0;
    dp.assign(n+5,vector<int>(k+5,-1));
    for (int i = 1; i <= n; i++) {
        ans = (ans + solve(i, 1)) % mod;
    }
    cout << ans << endl;
    return 0;
}
