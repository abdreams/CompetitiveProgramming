#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> inparr(x);
    for (int& a : inparr) {
        cin >> a;
        a--;
    }
    sort(inparr.begin(), inparr.end());

    vector<int> odd_ka_frk, eve_ka_frk;

    for (int i = 0; i < x; ++i) {
        int farak = (inparr[(i + 1) % x] - inparr[i] + n) % n;
        if (farak >= 3) {
            int bekar = farak - 1;
            if (bekar % 2 == 1) {
                odd_ka_frk.push_back(bekar);
            } else {
                eve_ka_frk.push_back(bekar);
            }
        }
    }

    sort(odd_ka_frk.begin(), odd_ka_frk.end());
    int z = n;

    for (int x : odd_ka_frk) {
        if (y >= x / 2) {
            y -= x / 2;
            x = 0;
        } else {
            int a=min(y,x/2);
            x-=2*a;
            y-=a;
            z-=x;
        } 
        
    }


    for (int x : eve_ka_frk) {
            int a=min(y,x/2);
            x-=2*a;
            y-=a;
            z-=x;
    }

    cout << (z - 2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
