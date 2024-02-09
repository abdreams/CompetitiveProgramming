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
    vector<int>wht(n,0);
    vector<int>blk(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>wht[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>blk[i];
    }
    sort(wht.begin(),wht.end());
    sort(blk.begin(),blk.end());

    int len=0;

    for(int i=0;i<n;i++){
        len+=abs(wht[i]-blk[i]);
    }
    cout<<len<<endl;
    
    return 0;
}