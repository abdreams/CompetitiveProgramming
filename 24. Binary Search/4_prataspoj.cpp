#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isPossible(int p, int l, vector<int>& arr, int time) {
    int parathas = 0;
    for (int i = 0; i < l; i++) {
        int rank = arr[i];
        int count = 0;
        int j = 1;
        while ((j * (j + 1) / 2) * rank <= time) {
            count++;
            j++;
        }
        parathas += count;
    }
    return parathas >= p;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int p;
        cin >> p;
        int l;
        cin >> l;
        vector<int> arr(l, 0);
        for (int i = 0; i < l; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        int low = 0, high = INT_MAX;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(p, l, arr, mid)) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
