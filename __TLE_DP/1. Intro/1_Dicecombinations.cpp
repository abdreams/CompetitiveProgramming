//https://cses.fi/problemset/task/1633

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=(int)1e9+7;
vector<int>dp(10000005,-1);

int solve(int n){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int ans=0;
    for(int i=1;i<=6;i++){
        ans=(ans+solve(n-i))%MOD;
    }
    return dp[n]=ans;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n; 

    int ans=solve(n);
    cout<<ans<<endl;

    return 0;
}
