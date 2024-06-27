#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k > (n + 1) / 2) {
        cout << -1 << endl;
        return;
    }

    vector<int> a(n);

    for (int i = 0; i < n; ++i)
        a[i] = i + 1;

    for (int i = 1; i <= k; ++i)
        a[n - i] = i;

    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
