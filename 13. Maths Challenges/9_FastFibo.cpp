#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll k;
vector<ll> a, b, c;

vector<vector<ll>> multiply(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    vector<vector<ll>> C(k + 1, vector<ll>(k + 1));

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            for (int x = 1; x <= k; x++) {
                C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % MOD) % MOD;
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

ll compute(ll n) {
    if (n == 0) {
        return 0;
    }

    if (n <= k) {
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

    T = pow(T, n - 1);

    ll res = 0;
    for (int i = 1; i <= k; i++) {
        res = (res + (T[1][i] * F1[i]) % MOD) % MOD;
    }

    return res;
}

int main() {
    ll t, n;

    k = 2;
    b.push_back(0);
    b.push_back(1);

    c.push_back(1);
    c.push_back(1);

    cin >> t;
    while (t--) {
        cin >> n;
        cout << compute(n + 1) << endl;
    }

    return 0;
}
