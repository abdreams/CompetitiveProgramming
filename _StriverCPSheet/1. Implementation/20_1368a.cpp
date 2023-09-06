#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t;
    ll a,b,n;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        ll sum = 0,c = 0;
        while(sum <= n){
            if(a > b){
                b += a;
                sum = b;
                c++;
            }
            else{
                a += b;
                sum = a;
                c++;
            }
            if(sum > n){
                break;
            }
        }
        cout<<c<<endl;
    }

    return 0;
    
}
