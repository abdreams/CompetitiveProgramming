// semper fi //
// abdreams //
//https://codeforces.com/problemset/problem/1389/B//


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

int solve(int ind, int left_move_count, int total_move_count, int k, int z, vector<int> &arr,
          vector<vector<vector<int>>>&dp, bool can_move_left) {
    int n = arr.size();
    if (ind == n || left_move_count >= z + 1 || total_move_count >= k + 1) {
        return 0;
    }
    
    if (dp[ind][left_move_count][can_move_left] != -1) {
        return dp[ind][left_move_count][can_move_left];
    }

    int sum_left = 0;

    if (left_move_count < z && ind != 0 && can_move_left == true) {
        sum_left = arr[ind] + solve(ind - 1, left_move_count + 1, total_move_count + 1, k, z, arr, dp, false);
    }

    int sum_right = arr[ind] + solve(ind + 1, left_move_count, total_move_count + 1, k, z, arr, dp, true);

    dp[ind][left_move_count][can_move_left] = max(sum_left, sum_right);
    return dp[ind][left_move_count][can_move_left];
}

int32_t main() {
    ab_d();
    w(x) {
        int n, k, z;
        cin >> n >> k >> z;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(z + 1, vector<int>(2, -1)));
        
        cout << solve(0, 0, 0, k, z, arr, dp, true) << endl;
    }

    return 0;
}

