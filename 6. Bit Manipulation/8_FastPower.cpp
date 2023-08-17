#include<bits/stdc++.h>

using namespace std;

int power_optimized(int a,int n){
    int ans=1;

    while(n>0){
        int last_bit=(n&1);
        if(last_bit==1){
            ans=ans*a;
        }
        a=a*a;
        n=n>>1;
    }
    return ans;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int a,n;
    cin>>a>>n; 

    cout<<a<<" to the power " << n<< " is: "<<power_optimized(a,n)<<endl;

    return 0;
}
