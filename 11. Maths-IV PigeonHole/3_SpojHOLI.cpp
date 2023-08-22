#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll inf = (int) 1e18;
ll mod =(int) 1e9 + 7;

vector<pair<ll, ll>> adj[100005];

ll ret = 0;
ll n;


ll dfs(ll par, ll u) {
    ll ans = 1;
    for (ll i = 0; i < adj[u].size(); i++) {
        ll v = adj[u][i].first;
        ll wt = adj[u][i].second;

        if (v == par) continue;

        ll nodes = dfs(u, v);
        ret += 2 * min(nodes, n - nodes) * wt;
        // reverse pigeon hole 
        ans += nodes;
    }
    return ans;
}

int main() {
    ll t = 1;
    cin >> t;
    ll tc = 1;
    while (t--) {
        ret = 0;
        cin >> n;
        for (ll i = 1; i <= n; i++) adj[i].clear();

        for (ll i = 1; i < n; i++) {
            ll u, v, x;
            cin >> u >> v >> x;
            adj[u].push_back({v, x});
            adj[v].push_back({u, x});
        }

        dfs(-1, 1);
        cout << "Case #" << tc++ << ": " << ret << endl;
    }
}

