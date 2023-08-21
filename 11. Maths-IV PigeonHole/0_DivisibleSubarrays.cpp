//https://hack.codingblocks.com/app/practice/1/1065/problem

#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int>arr;
    vector<int>pre(n,0);
    int sum=0;
    pre[0]=1;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
        sum+=x;
        sum%=n;
        sum=(sum+n)%n;
        pre[sum]++;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int m=pre[i];
        ans+=(pre[i]*(pre[i]-1))/2;
    }
    cout<<ans<<endl;
    }

    return 0;
}
