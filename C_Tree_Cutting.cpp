#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int k, vector<int> &v, int n) {
    int prev = 0;
    for (int i = 0; i < n; i++) {
        int mn = v[i] - k;
        int mx = v[i] + k;
        bool flag = false;
        
        // Adjust mn to ensure it's not less than prev
        mn = min(mx, max(prev, mn));

        for (int j = mn; j <= mx; j++) {
            if (j < prev) continue;
            prev = j;
            flag = true;
            break;
        }
        if (!flag) return false;
    }
    return true;
}

int findMinimum(int n, vector<int> &v) {
    int low = 0;
    int high = 1e5;
    int ans = 0;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (check(mid, v, n)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> degrees(n, 0);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            degrees[u - 1]++;
            degrees[v - 1]++;
        }
        int result = findMinimum(n, degrees);
        cout << result << endl;
    }
    return 0;
}
