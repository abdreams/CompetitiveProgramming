//semper fi//https://cses.fi/problemset/task/1639

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

int solve(int i,int j,string&a,string&b){
    if(i<0) return j+1;
    if(j<0) return i+1;

    if(dp[i][j]!=-1) return dp[i][j];

    if(a[i]==b[j]){
        return dp[i][j]=0+solve(i-1,j-1,a,b);
    }
    //update add remove three possibilities
    else 
        return dp[i][j]=1+min(solve(i-1,j-1,a,b),min(solve(i-1,j,a,b),solve(i,j-1,a,b)));
    
}

int32_t main(){
ab_d();
    string a;
    string b;
    cin>>a>>b;

    dp.assign(a.size(),vector<int>(b.size(),-1));

    cout<<solve(a.size()-1,b.size()-1,a,b)<<endl;

    return 0;
}
