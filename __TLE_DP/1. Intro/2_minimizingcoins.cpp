//https://cses.fi/problemset/task/1634/
/*
author: @abdreams
|| semper fi ||
*/
#include <bits/stdc++.h>
#define int long long
#define w(x)            int x; cin>>x; while(x--)
#define int long long
using namespace std;

const int INF = 1e18;
 
int solve(vector<int> &coins, int target, vector<int> &dp) {
    if (target == 0) return 0;
    if (dp[target] != -1) return dp[target];

    int bestAns = 1e18;
    for(int i=0 ; i<coins.size() ; i++){
        if(target >= coins[i]){
            bestAns = min(bestAns , solve(coins , target-coins[i] , dp)+1);
        }
    }
    return dp[target] = bestAns;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt" , "w" , stderr);
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
    sort(coins.begin(),coins.end());
    debug(coins)
    
    int ans = solve(coins, target, dp);
    if (ans >= INF) cout << -1 << endl;
    else cout << ans << endl;
    
    debug(dp)
 
    return 0;
}
// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// const int INF = 1e18;

// int solve(int ind, vector<int> &coins, int target, vector<int> &dp) {
//     if (target == 0) return 0;
//     if (ind < 0) return INF;
//     if (dp[target] != -1) return dp[target];

//     int take = INF;

//     if (target >= coins[ind]) {
//         take = 1 + solve(ind, coins, target - coins[ind], dp);
//     }
    
//     int notTake = solve(ind - 1, coins, target, dp);

    
//     return dp[target] = min(take, notTake);
// }

// int32_t main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     int n;
//     cin >> n; 
//     int target;
//     cin >> target;
//     vector<int> coins(n);
//     vector<int> dp(target + 1, -1);
    
//     for (int i = 0; i < n; i++) {
//         cin >> coins[i];
//     }
//     sort(coins.rbegin(),coins.rend());
    
//     int ans = solve(n - 1, coins, target, dp); 
//     if (ans >= INF) cout << -1 << endl;
//     else cout << ans << endl;

//     return 0;
// }