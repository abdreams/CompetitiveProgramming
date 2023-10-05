#include<bits/stdc++.h>

using namespace std;

int lastOccur(int arr[],int n,int num){
    if(n==-1)
        return -1;
    
    if(arr[n]==num)
        return n;
    
    return lastOccur(arr,n-1,num);
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
    
    int num;
    cin>>num;

    int ans=lastOccur(arr,n,num);
    cout<<ans<<endl;
    return 0;
}
