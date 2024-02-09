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
    int n;
    cin>>n;
    vector<int>a(n,0);
    vector<int>dp(n+1,0);

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    

    dp[0] = a[0]>0?a[0]:0;
    int maxi=dp[0];

    for (int i = 1; i < n; i++)
    {
        dp[i]=dp[i-1]+a[i];
        if(dp[i]<0) dp[i]=0;
        maxi=max(maxi,dp[i]);
    }

    
    cout << maxi;
    
    return 0;
}
