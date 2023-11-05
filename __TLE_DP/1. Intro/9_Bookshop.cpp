//semper fi//https://cses.fi/problemset/task/1158

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

// #define int long long
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

int solve(int ind,int money,vector<int>&prices, vector<int>&pages){
    if(money<=0) return 0;
    if(ind==0){
        if(money>=prices[ind]) return pages[ind];
        else return 0;
    }

    if(dp[ind][money]!=-1) return dp[ind][money];

    int take=LLONG_MIN;
    if(money>=prices[ind]){
        take=pages[ind]+solve(ind-1,money-prices[ind],prices,pages);
    }
    int nottake=solve(ind-1,money,prices,pages);

    return dp[ind][money]=max(take,nottake);
}

int32_t main(){
ab_d();
    int n,money;
    cin>>n>>money;
    vector<int>prices(n);

    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    vector<int>pages(n);

    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    dp.assign(n,vector<int>(money+1,-1));
    cout<<solve(n-1,money,prices,pages)<<endl;
    
    return 0;
}
