// semper fi //
// abdreams //
// https://codeforces.com/contest/1498/problem/C

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

vector<vector<int>>dp;


int solve(int fwd_mirrors, int bk_mirrors, int decay){
    
    if(decay==1 or fwd_mirrors==0){
        return 1;
    }

    if(dp[fwd_mirrors][decay]!=-1) return dp[fwd_mirrors][decay];

    return
    dp[fwd_mirrors][decay]=
    (solve(bk_mirrors,fwd_mirrors,decay-1)+solve(fwd_mirrors-1,bk_mirrors+1,decay))%mod;
}


int32_t main(){
ab_d();
    w(t){
        int n,k;
        cin>>n>>k;
        dp.assign(n+5, vector<int>(k+5,-1));
        cout<<solve(n,0,k)<<endl;
      
    }

    return 0;
}
