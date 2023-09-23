#include<bits/stdc++.h>
#define int long long
using namespace std;

bool check(int seconds, vector<int>& attack_times, int n, int h) {

    int total_points_for_seconds = 0;

        for (int i = 1; i < n; i++) {

            if (attack_times[i] - attack_times[i-1] >= seconds) {
                total_points_for_seconds += seconds;
            }

            else {
                total_points_for_seconds += attack_times[i] - attack_times[i-1];
            }

        } 

    total_points_for_seconds+=seconds;
    
    if (total_points_for_seconds >= h) return true;

    return false;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    while (t--) {
        int n, h;
        cin >> n >> h;
        vector<int> attack_times(n);
        for (int i = 0; i < n; i++) {
            cin >> attack_times[i];
        }
            int l = 0;
            int r = 1e18;
            int ans = 0;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (check(mid, attack_times, n, h)) {
                    ans = mid;
                    r=mid-1; 
                }
                else {
                    l=mid+1;
                }
            }
            cout << ans << endl;
        }

    return 0;
}

// 3
// 4
// 1
// 470