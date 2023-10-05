#include<bits/stdc++.h>

using namespace std;

void solve(int n,int arr[],int numtofind,int lengthofarr){
    if(n>=lengthofarr){
        cout<<"not found!";
        return;
    }
    if(arr[n]==numtofind) {
        cout<<"num found at index: "<< n;
        return;
    }
    if(arr[n]>numtofind){
        solve(n-1,arr,numtofind,lengthofarr);
    }
    if(arr[n]<numtofind){
        solve(n+1,arr,numtofind,lengthofarr);
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int numtofind=0;
    cin>>numtofind;

    solve(n/2,arr,numtofind,n);
}
