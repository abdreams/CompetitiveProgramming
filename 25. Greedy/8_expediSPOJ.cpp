#include <bits/stdc++.h>
using namespace std;

#define int long long

void ab_d() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int32_t main() {
    ab_d();

    int t;
    cin >> t;

    while (t--) {
        int n, dest, initFuel, dist, fuel;
        cin >> n;

        int cantReach = 0, stops = 0;
        vector<pair<int, int>> fuelStops;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            fuelStops.push_back({a, b});
        }

        sort(fuelStops.rbegin(), fuelStops.rend());

        cin >> dest >> initFuel;

        for (int i = 0; i < n; i++) {
            fuelStops[i].first = dest - fuelStops[i].first;
        }

        int last = 0;
        int curr = 0;

        while (curr < n) {
            if (initFuel >= (fuelStops[curr].first - last)) {
                initFuel -= (fuelStops[curr].first - last);
                pq.push(fuelStops[curr].second);
                last = fuelStops[curr].first;
            } else {
                if (pq.empty()) {
                    cantReach = 1;
                    break;
                }
                initFuel += pq.top();
                pq.pop();
                stops++;
                continue;
            }
            curr++;
        }

        if (cantReach) {
            cout << -1 << endl;
            continue;
        }

        dest = dest - fuelStops[n - 1].first;
        if (initFuel >= dest) {
            cout << stops << endl;
            continue;
        }

        while (initFuel < dest) {
            if (pq.empty()) {
                cantReach = 1;
                break;
            }
            initFuel += pq.top();
            pq.pop();
            stops++;
        }

        if (cantReach) {
            cout << -1 << endl;
            continue;
        }

        cout << stops << endl;
    }

    return 0;
}
