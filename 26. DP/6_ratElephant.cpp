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
int n,m,k;

int solve(int i,int j){
    if(i==n-1 and j==m-1) return 1;
    if(i>=n or i<0 or j>=m or j<0) return 0;

    int right=0;
    int down=0;
    for (int x = 0; x < k+1; x++)
    {
        right+=solve(i,j+x);
        down+=solve(i+x,j);
    }
    return right+down;
}

int32_t main(){
ab_d();
    cin>>n>>m>>k;

    cout<<solve(0,0);
    

    return 0;
}
