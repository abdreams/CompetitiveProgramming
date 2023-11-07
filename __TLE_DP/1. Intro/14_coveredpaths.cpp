// semper fi //
// abdreams //
// https://codeforces.com/contest/534/problem/B

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

int v1,v2;
int t,d;
vector<vector<int>>dp;

int solve(int cur_speed,int time){
    if(time==t-1){
        if(cur_speed==v2) return v2;
        return LLONG_MIN;
    }

    if(dp[cur_speed][time]!=-1) return dp[cur_speed][time];

    int ans=LLONG_MIN;
    for(int i=cur_speed-d;i<=cur_speed+d;i++){
        if(i>=0 and i<1005){
            ans=max(ans,solve(i,time+1));
        }
    }
    ans+=cur_speed;
    return dp[cur_speed][time]=ans;
}

int32_t main(){
ab_d();
    cin>>v1>>v2;
    cin>>t>>d;
    dp.assign(1005,vector<int>(105,-1));
    cout<<solve(v1,0)<<endl;

    return 0;
}
