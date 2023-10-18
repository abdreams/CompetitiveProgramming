#include<bits/stdc++.h>

using namespace std;

int solve(string str,int n,int num){
    if(n==str.size()-1) return num+(str[n]-'0'); //2048
    num=num+(str[n]-'0');
    num=num*10;
    return solve(str,n+1,num);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    string str;
    cin>>str; 
    int ans;
    ans=solve(str,0,0);
    cout<<ans<<endl;

    return 0;
}
