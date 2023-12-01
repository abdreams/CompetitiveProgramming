#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>


using namespace __gnu_pbds;
using namespace std;

#define int long long
#define setbits(x) __builtin_popcountll(x)
#define mod 1000000007
#define inf 1e18
#define w(x) int x; cin >> x; while (x--)p

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void ab_d() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool canObtainArray(vector<int> &b, int k) {
    int n = b.size();

    int minElement = *min_element(b.begin(), b.end());
    
    if (k % 2 == 0) {
        for (int i = 0; i < n; i++) {
            if (b[i] != minElement and b[i]==b[i-1]) {
                return false;
            }
        }
        return true;
    } else {
        for (int i = 0; i < n; i++) {
            if (b[i] != minElement) {
                return false;
            }
            if (i + 1 < n && b[i] == b[i + 1]) {
                return true;
            }
        }
        return false;
    }
   
}

int32_t main() {
    ab_d();

    w(t) {
        int n, k;
        cin >> n >> k;
        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        bool possible = canObtainArray(b, k);
        cout << (possible ? "Yes" : "No") << endl;
            
        }
    }

    return 0;
}
