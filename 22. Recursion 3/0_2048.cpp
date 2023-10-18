#include<bits/stdc++.h>

using namespace std;

void solve(int n){
    if(n==0) return;
    solve(n/10);
    int num=n%10;
    string dig;
    if(num==1) dig="one";
    else if(num==2) dig="two";
    else if(num==3) dig="three";
    else if(num==4) dig="four";
    else if(num==5) dig="five";
    else if(num==6) dig="six";
    else if(num==7) dig="seven";
    else if(num==8) dig="eight";
    else if(num==9) dig="nine";
    else if(num==0) dig="zero";
    cout<<dig<<" ";
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n; // 2048
    solve(n);

    return 0;
}
