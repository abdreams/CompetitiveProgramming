#include<bits/stdc++.h>
#define ld long double
using namespace std;

typedef long long int ll;

ll n, m;
ld dp[3000][3000];
bool d[3000][3000];
vector<ld> v[2];

ld calc(int x, int heads, int tails) {
    if (x == n) return heads > tails;
    if (d[heads][tails]) return dp[heads][tails];

    d[heads][tails] = 1;
    return dp[heads][tails] = calc(x + 1, heads + 1, tails) * v[0][x] + calc(x + 1, heads, tails + 1) * v[1][x];
}

int32_t main() {
    cin >> n;
    v[0] = vector<ld>(n);
    v[1] = vector<ld>(n);

    for (int i = 0; i < n; i++) {
        cin >> v[0][i];
        v[1][i] = 1 - v[0][i];
    }

    cout << setprecision(10) << fixed << calc(0, 0, 0) << endl;

    return 0;
}
