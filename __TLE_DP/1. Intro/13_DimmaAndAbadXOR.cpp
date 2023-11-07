// semper fi //
// abdreams //
// 

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

void ab_d() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int MAXN = 505;
const int MAXM = 505;
const int MAXVAL = 1025;

int n, m;
int a[MAXN][MAXM];
int dp[MAXN][MAXM];

int solve(int row, int prev_xor) {
    if (row == n) {
        return prev_xor > 0 ? 1 : 0;
    }

    if (dp[row][prev_xor] != -1) {
        return dp[row][prev_xor];
    }

    for (int col = 0; col < m; col++) { 
        int new_xor = prev_xor ^ a[row][col];
        if (new_xor > 0) {
            dp[row][prev_xor] = 1;
            return dp[row][prev_xor];
        }
        if (solve(row + 1, new_xor)) {
            dp[row][prev_xor] = 1;
            return dp[row][prev_xor];
        }
    }

    dp[row][prev_xor] = 0;
    return dp[row][prev_xor];
}

int32_t main() {
    ab_d();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    if (solve(0, 0)) {
        cout << "TAK" << endl;
        int row = 0, prev_xor = 0;
        while (row < n) {
            for (int col = 0; col < m; col++) {
                int new_xor = prev_xor ^ a[row][col];
                if (new_xor > 0 || (row == n - 1)) {
                    cout << col + 1 << " ";
                    prev_xor = new_xor;
                    row++;
                    break;
                }
            }
        }
    } else {
        cout << "NIE" <<endl;
    }
}