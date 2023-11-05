//semper fi//https://atcoder.jp/contests/dp/tasks/dp_c

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

vector<vector<int>> dp;

int solve(int day, int last, vector<vector<int>>& rewards) {
    int n=rewards.size();
    if (day == n - 1) {
        int maxi = 0;
        for (int i = 0; i <= 2; i++) {
            if (i != last) {
                maxi = max(maxi, rewards[day][i]);
            }
        }
        return maxi;
    }

    if (dp[day][last] != -1) {
        return dp[day][last];
    }

    int maxi = 0;
    for (int i = 0; i <= 2; i++) {
        if (i != last) {
            int points = rewards[day][i] + solve(day + 1, i, rewards);
            maxi = max(maxi, points);
        }
    }

    dp[day][last] = maxi;
    return maxi;
}

int32_t main(){
    ab_d();

    int n;
    cin >> n;
    vector<vector<int>> rewards(n, vector<int>(3, -1));

    for (int i = 0; i < n; i++) {
        cin >> rewards[i][0] >> rewards[i][1] >> rewards[i][2];
    }

    dp.assign(n, vector<int>(3, -1));
    cout << max(solve(0, 2, rewards), max(solve(0, 1, rewards), solve(0, 0, rewards))) << endl;

    return 0;
}
