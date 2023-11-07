// semper fi //
// abdreams //
// https://cses.fi/problemset/task/1636

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

// int num_coins, target;
// vector<int> coins;
// vector<vector<int>> memo;

// int solve(int ind, int rem) {
//     if (ind == 0) {
//         if (rem%coins[ind]==0) return 1;
//         return 0;
//     }

//     if (memo[ind][rem] != -1) {
//         return memo[ind][rem];
//     }

//     int take = 0;
//     if (coins[ind] <= rem)
//         take = solve(ind, rem - coins[ind]);

//     int notTake = solve(ind - 1, rem);

//     return memo[ind][rem] = (take + notTake) % mod;
// }
void solve_cses(){
    int n, x;
    cin>>n>>x;
 
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];
 
    vector<int> ways(x+1);
    ways[0] = 1;
 
    int MOD = 1e9 + 7;
 
    for(auto e: c)
    {
        for(int i=0; i<=x-e; i++)
            (ways[i+e] += ways[i]) %= MOD;
    }
 
    cout<<ways[x]<<"\n";
}

int32_t main() {
    ab_d();
    solve_cses();
    // Input
    // cin >> num_coins >> target;
    // coins.resize(num_coins);
    // for (int i = 0; i < num_coins; i++) cin >> coins[i];

    // memo.assign(num_coins, vector<int>(target + 1, -1));

    // cout << solve(num_coins - 1, target) << endl;

    return 0;
}
