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
        int x,y,n;
        cin>>x>>y>>n;
        int temp=n-y;
        int divi=(n-y)/x;
        int ans=(x*divi)+y;
        cout<<ans<<endl;
    }

    return 0;
}
