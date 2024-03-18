#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long

const int INF = 1e18;

int dp[2005][2005];

int solve(int i, int j, int n, int l, vector<int>& a, vector<int>& b) {
    if (i > n) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if (j + 1 <= l) {
        ans = max(ans, solve(i + 1, j + 1, n, l, a, b) + a[i]);
    }
    ans = max(ans, solve(i + 1, j, n, l, a, b) + max(0LL, a[i] - b[i]));

    return dp[i][j] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, l;
        cin >> n >> l;

        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }

        int low = 1, high = n, result = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            memset(dp, -1, sizeof(dp));

            if (solve(0, 0, n - 1, mid, a, b) <= l) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << result << endl;
    }

    return 0;
}
