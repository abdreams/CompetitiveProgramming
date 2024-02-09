#include<bits/stdc++.h>
using namespace std;

#define int long long

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}


vector<int> dp;

int CellMitosis(int n, int x, int y, int z) {
    if (n <= 1) return 0;

    if (dp[n] != -1) {
        return dp[n];
    }

    int mincost = INT_MAX;
    if (n % 2 == 0) {
        mincost = min(mincost, x + CellMitosis(n / 2, x, y, z));
        mincost = min(mincost, y + CellMitosis(n - 1, x, y, z));
    } else {
        mincost = min(mincost, x + z + CellMitosis((n + 1) / 2, x, y, z));
        mincost = min(mincost, y + CellMitosis(n - 1, x, y, z));
    }

    return dp[n] = mincost;

    
}

int main() {
ab_d();
    int n, x, y, z;
    cin >> n;
    cin >> x >> y >> z;

    dp.resize(n + 1, -1);

    cout << CellMitosis(n, x, y, z) << endl;
    return 0;
}
