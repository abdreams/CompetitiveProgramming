#include <iostream>
#include <vector>

using namespace std;

int query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    fflush(stdout);
    
    int d;
    cin >> d;
    return d;
}

void solve() {
    int n, m;
    cin >> n >> m;

    int d1 = query(1, 1);
    int d2 = query(1, m);
    int d3 = query(n, 1);
    int d4 = query(n, m);

    int minDistance = min({d1, d2, d3, d4});

    if (minDistance == d1 || minDistance == d3) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (query(i, j) == 0) {
                    cout << "! " << i << " " << j << endl;
                    return;
                }
            }
        }
    } else {
        for (int i = n; i >= 1; i--) {
            for (int j = m; j >= 1; j--) {
                if (query(i, j) == 0) {
                    cout << "! " << i << " " << j << endl;
                    return;
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
