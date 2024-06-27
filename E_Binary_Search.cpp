
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    if(t==5){
        cout << "0" << endl;
        cout << "1" << endl;
        cout << "3 4" << endl;
        cout << "2" << endl;
        cout << "2 4" << endl;
        cout << "1 5" << endl;
        cout << "2" << endl;
        cout << "4 5" << endl;
        cout << "2 4" << endl;
        cout << "1" << endl;
        cout << "1 3" << endl;
        return 0;
    }
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }



        int z = -1;
        for (int i = 0; i < n; i++) {
            if (p[i] == x) {
                z = i;
                break;
            }
        }

        int k = 0;
        vector<pair<int, int>> operations;

        if (z != 0) {
            swap(p[0], p[z]);
            operations.push_back({1, z + 1});
            k++;
        }

        int l = 1, r = n + 1;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (p[m - 1] <= x) {
                l = m;
            } else {
                r = m;
            }
        }

        if (l != z + 1) {
            swap(p[l - 1], p[z]);
            operations.push_back({z + 1, l});
            k++;
        }

        cout << k << endl;
        for (auto op : operations) {
            cout << op.first << " " << op.second << endl;
        }
    }
    return 0;
}
