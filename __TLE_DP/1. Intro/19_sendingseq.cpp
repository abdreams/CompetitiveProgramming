// semper fi //
// abdreams //
// https://codeforces.com/contest/1741/problem/E

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define w(x)            int x; cin>>x; while(x--)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
int n;
vector<int>v;
vector<int>dp;

int solve(int ind){
    if(ind==-1 or ind==n) return 1;

    if(dp[ind]!=-1) return dp[ind];

    int leftvalid=0;
    int rightvalid=0;

    if(ind-v[ind]-1>=-1)
        leftvalid=solve(ind-v[ind]-1);

    if(ind+v[ind]+1<=n)
        rightvalid=solve(ind+v[ind]+1);
    
    return dp[ind]=(leftvalid or rightvalid);
}

int32_t main(){
ab_d();
    w(x){
        cin>>n;
        v.assign(n,-1);
        dp.assign(n+5,-1);

        for(int i=0;i<n;i++) cin>>v[i];

        int ans = solve(n-1);
        if (ans == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}


