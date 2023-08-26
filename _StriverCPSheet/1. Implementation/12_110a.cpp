#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n;
    int count=0;
    while(n!=0){
        int temp=n%10;
        if(temp==4 or temp==7) count++;
        n=n/10;
    }
    if(count==4 or count==7) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
