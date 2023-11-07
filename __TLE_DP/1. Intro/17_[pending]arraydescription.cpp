// semper fi //
// abdreams //
// https://cses.fi/problemset/task/1746

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define w(x)            int x; cin>>x; while(x--)
#define ll long long

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
vector<vector<ll>>dp;
 
ll solve(vector<ll>&arr, ll idx, int x, ll bound)
{
    if(idx==0 || x==0) return 0;
 
    if(x>bound) return 0;
 
    if(dp[idx][x]!=-1) return dp[idx][x];
 
    if(idx==1)
    {
        if(arr[idx]==0 || arr[idx]==x) return 1;
 
        else return 0;
    }
    
    ll ans=0;
    if(arr[idx]==0 || arr[idx]==x)
    {
        ans = (ans + solve(arr, idx - 1, x - 1, bound)%mod) % mod;
        ans = (ans + solve(arr, idx - 1, x, bound)%mod) % mod;
        ans = (ans + solve(arr, idx - 1, x + 1, bound)%mod) % mod;
    }
 
    else return 0;
 
    return dp[idx][x]=ans%mod;
 
}
 
int32_t main()
{
    ab_d();
    ll n,m;
    cin>>n>>m;
 
    vector<ll>arr(n+1);
 
    dp.resize(n+2,vector<ll>(m+2,-1));
 
    for(int i=1; i<=n; i++) cin>>arr[i];
    
    ll res=0;
    for(int i=1; i<=m; i++) res = (res + (solve(arr,n,i,m)))%mod;
 
    cout<<res<<endl;
}