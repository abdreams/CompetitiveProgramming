//https://cses.fi/problemset/task/1635/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1000000007;

int solve(int target, vector<int> &coins, vector<int> &dp) {
    if (target == 0) return 1;
    if (dp[target] != -1) return dp[target];

    int ways = 0;

    for (int coin : coins) {
        if (target >= coin) {
            ways = (ways + solve(target - coin, coins, dp)) % MOD;
        }
    }

    return dp[target] = ways;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> coins(n);
    vector<int> dp(target + 1, -1);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int ans = solve(target, coins, dp);

    cout << ans << endl;

    return 0;
}
/*
we couldnt do this because this q counts 2 2 5 and 2 5 2 and 5 2 2 as different so we need to 
explore those combinations too.

int solve(int ind, vector<int> &coins, int target, vector<int> &dp) {
    if (target == 0) return 1;
    if (ind < 0) return 0;
    if (dp[target] != -1) return dp[target];

    int take = 0;

    if (target >= coins[ind]) {
        take = solve(ind, coins, target - coins[ind], dp);
    }
    
    int notTake = solve(ind - 1, coins, target, dp);
    
    return dp[target] = take+notTake;
}
*/

