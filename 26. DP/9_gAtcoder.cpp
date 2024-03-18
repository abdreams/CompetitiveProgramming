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

int solve(int node, vector<vector<int>>&adj, vector<int>& dp){

    if(adj[node].size()==0) return dp[node] = 0;

    if(dp[node] != -1) return dp[node];

    int ans = 0;

    for(auto it : adj[node])
        ans = max(ans, 1 + solve(it, adj, dp));

    return dp[node] = ans;
}

int32_t main(){
    ab_d();
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> dp(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    int maxi = INT_MIN;
    for (int i = 1; i <= n; i++) {
        maxi = max(maxi, solve(i, adj, dp));
    }
    
    cout << maxi << endl;
    return 0;
}
