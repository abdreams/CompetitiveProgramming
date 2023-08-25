// https://www.spoj.com/problems/SPP/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll p;

ll k;
vector<ll> b, c;

vector<vector<ll>> multiply(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    vector<vector<ll>> C(k + 1, vector<ll>(k + 1));

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            for (int x = 1; x <= k; x++) {
                C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % p) % p;
            }
        }
    }
    
    return C;
}

vector<vector<ll>> pow(const vector<vector<ll>>& A, ll p) {
    if (p == 1) {
        return A;
    }
    if (p & 1) {
        return multiply(A, pow(A, p - 1));
    } else {
        vector<vector<ll>> X = pow(A, p / 2);
        return multiply(X, X);
    }
}

ll compute(ll m, ll n) {
    if (m == 0) {
        return 0;
    }

    if (m <= k) {
        return b[n - 1];
    }

    vector<ll> F1(k + 1);

    for (int i = 1; i <= k; i++) {
        F1[i] = b[i - 1];
    }

    vector<vector<ll>> T(k + 1, vector<ll>(k + 1));

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            if (i < k) {
                if (j == i + 1) {
                    T[i][j] = 1;
                } else {
                    T[i][j] = 0;
                }
                continue;
            }
            T[i][j] = c[k - j];
        }
    }

    T = pow(T, n - m + 1);

    ll res = 0;
    for (int i = 1; i <= k; i++) {
        res = (res + (T[1][i] * F1[i]) % p) % p;
    }

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ll t, n, m;

    cin >> t;
    while (t--) {
        cin >> k;

        b.clear();
        c.clear();

        for (int i = 0; i < k; i++) {
            ll bi;
            cin >> bi;
            b.push_back(bi);
        }

        for (int i = 0; i < k; i++) {
            ll ci;
            cin >> ci;
            c.push_back(ci);
        }

        cin >> m >> n >> p;
        cout << compute(m, n) << endl;
    }

    return 0;
}
