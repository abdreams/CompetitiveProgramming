//https://cses.fi/problemset/task/1635/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define w(x)            int x; cin>>x; while(x--)
#define  endl "\n"


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


const int MOD = 1000000007;


void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

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
ab_d();

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

