#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n,k;
    cin>>n>>k;

    while(k--){
        if(n%10==0){
            n=n/10;
        }
        else n=n-1;
    }
    cout<<n<<endl;
}
