/*
a person can jump 1/2/3 steps calculate the total number of ways he can reach the top
*/

#include<bits/stdc++.h>

using namespace std;

int solve(int i){
    if(i==0) return 1;
    if(i<0) return 0;

    int steps=solve(i-1)+solve(i-2)+solve(i-3);
    return steps;
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
}
