#include<bits/stdc++.h>
#define int long long
using namespace std;

int fastModulo(int a,int b,int m){
    int ans=1;
    while(b>0){
        if(b&1){
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return ans;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--){
    int a,b,m;
    cin>>a>>b>>m;

    cout<<fastModulo(a,b,m)<<endl;
    }
    return 0;
}
