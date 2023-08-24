#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    string x;
    cin>>x;

    for(auto &it:x){
        if(it>='5'){
            it='9'-it+'0';
        }
    }
    while(x.front()=='0') x.front()='9';

    cout<<x<<endl;
    
}
