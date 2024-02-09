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


int32_t main(){
ab_d();
    int t;
    cin>>t;
    while (t--)
    {
        int w, h, n;
        cin >> w >> h >> n;
        // vector<pair<int,int>> coor(n);
        vector<int> x(n+2), y(n+2);

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            // coor[i].first = a;
            // coor[i].second = b;
            x[i+1] = a;
            y[i+1] = b;
        }
        x[0] = 0;
        x[n+1] = w + 1;
        y[0] = 0;
        y[n+1] = h + 1;
        
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        int maxi_x = 0;
        for (int i = 1; i <= n+1; i++)
            maxi_x = max(maxi_x, x[i] - x[i-1] - 1);

        int maxi_y = 0;
        for (int i = 1; i <= n+1; i++)
            maxi_y = max(maxi_y, y[i] - y[i-1] - 1);

        cout << maxi_x * maxi_y << endl;
    }
    return 0;
}
