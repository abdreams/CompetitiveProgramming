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

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int n, l, k;
vector<int> coordinates;
vector<int> time_limits;
vector<int> dist;
vector<vector<int>> memo;

int solve(int x, int kx) {
    if (x == n) return 0;
    if (kx == 0) return time_limits[n] * dist[n - 1] - time_limits[x] * dist[x];

    if (memo[x][kx] != -1)
        return memo[x][kx];

    int d = dist[x];
    int time = time_limits[x];

    int ans = LLONG_MAX;

    // If we don't remove a sign
    int time_taken = time * d + solve(x + 1, kx);
    ans = min(time_taken, ans);

    // If we remove a sign
    for (int i = x + 1; i <= n; i++) {
        int time_taken = time * d + solve(i, kx - 1);
        ans = min(time_taken, ans);
        d += dist[i];
    }

    memo[x][kx] = ans;
    return ans;
}

int32_t main() {
ab_d();
    cin >> n >> l >> k;

    coordinates.assign(n, -1);
    time_limits.assign(n, -1);
    dist.assign(n, -1);
    memo.assign(n+5, vector<int>(n+5,-1));

    for (int i = 0; i < n; i++) cin >> coordinates[i];
    for (int i = 0; i < n; i++) cin >> time_limits[i];

    coordinates.push_back(l);

    for (int i = 0; i < n; i++)
        dist[i] = coordinates[i + 1] - coordinates[i];

    dist.push_back(0);

    cout << solve(0, k) << endl;

    return 0;
}
