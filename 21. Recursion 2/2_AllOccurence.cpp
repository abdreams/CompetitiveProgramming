#include<bits/stdc++.h>

using namespace std;

void allOccur(int arr[],int n,int num){
    if(n==-1)
        return;
    
    if(arr[n]==num)
        cout<<n<<" ";
    
    allOccur(arr,n-1,num);
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

    allOccur(arr,n,num);
    return 0;
}
