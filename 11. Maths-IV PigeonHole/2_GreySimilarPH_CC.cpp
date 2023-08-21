//https://www.codechef.com/problems/GRAYSC

#include <iostream>
#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    // your code goes here
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(n>=130) { 
        cout<<"Yes";
        return 0;
    }
    

    else {

    int flag=-1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                int d=arr[i]^arr[j]^arr[k]^arr[l];
                if(d==0) flag=1;
                }
            }
        }
    }
    if(flag==-1) cout<<"No";
    else cout<<"Yes";
    }

    return 0;
}