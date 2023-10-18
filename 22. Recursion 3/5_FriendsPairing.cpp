#include<bits/stdc++.h>

using namespace std;

int solve(int i){
    if(i==0) return 1;
    if(i<0) return 0;

    int ways=1*solve(i-1)+((i-1)*solve(i-2));
    return ways;
}

int main(){
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
