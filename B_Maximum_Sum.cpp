#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int64_t n, k;
        cin >> n >> k;

        vector<int64_t> a(n);
        int64_t as = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            as += a[i];
        }

        int64_t sum = 0;
        int64_t maxi = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum < 0) {
                sum = 0;
            }
            maxi = max(maxi, sum);
        }

        
        int64_t power = 1;
        for (int i = 0; i < k; i++) {
            power = (power * 2) % MOD;
        }
        int64_t ans = (maxi * (power - 1)) % MOD;

        int64_t fin = (ans + as) % MOD;
        if (fin < 0) {
            fin += MOD;
        }

        cout << fin << endl;
    }

    return 0;
}