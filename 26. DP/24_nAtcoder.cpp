#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int dp[404][404];
int solve(int i, int j, vi &arr){
    if(i>=j) return 0 ;
    if(dp[i][j]!=-1) return dp[i][j];
    else{
        int ans = INT_MAX; 
        for(int k= i ;  k < j ; k++){
            ans = min(ans,arr[j] - arr[i-1] +solve(i,k,arr)+solve(k+1,j,arr));
        }
        return dp[i][j]= ans ;
    }
}
void ab_d(){
    int n;
    cin>>n;
    vi arr(n+1);
    arr[0]=0;
    
    for(int i = 1 ; i <= n ; i++) {
        int z;
        cin>>z;
        arr[i] = z + arr[i-1];
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,n,arr)<<endl;
}

