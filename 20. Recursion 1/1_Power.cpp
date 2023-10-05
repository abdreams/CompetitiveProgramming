#include<bits/stdc++.h>

using namespace std;


int solve(int a, int n){
    if(n==1){
        return a;
    }

    if(n%2==1){
        return a*(solve(a,(n/2)))*(solve(a,(n/2)));// 
    }
    return (solve(a,n/2)*solve(a,n/2));
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int a,n;
    cin>>a>>n; 

    int ans=solve(a,n);
    cout<<ans<<endl;
    
    return 0;
}
