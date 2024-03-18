#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> leftCoins(n);
        vector<int> rightCoins(m);

        for (int i = 0; i < n; ++i) {
            cin >> leftCoins[i];
        }

        for (int i = 0; i < m; ++i) {
            cin >> rightCoins[i];
        }

        sort(leftCoins.begin(), leftCoins.end());
        sort(rightCoins.begin(), rightCoins.end());

        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (leftCoins[i] + rightCoins[j] <= k) {
                    count++;
                } else {
                    break;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
