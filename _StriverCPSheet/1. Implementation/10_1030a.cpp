//https://codeforces.com/problemset/problem/1030/A

#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n; 
    int flag=-1;
    while(n--){
        int temp;
        cin>>temp;
        if(temp==0) continue;
        else if(temp==1) flag=1;
    }
    if(flag==-1) cout<<"EASY";
    else if(flag==1) cout<<"HARD";

}
