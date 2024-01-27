#include <bits/stdc++.h>
using namespace std;

#define int long long

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

bool isPossible(int mid, int n, int m, int x, int y) {
    int coupons_needed = mid * x;

    if (coupons_needed <= m + (n - mid) * y) {
        return true;
    }

    return false;
}

int32_t main(){
    ab_d();
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    int low = 0, high = n, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(mid, n, m, x, y)) {
            ans = mid;  
            low = mid + 1;  
        } else {
            high = mid - 1; 
        }
    }

    cout << ans << endl;

    return 0;
}
