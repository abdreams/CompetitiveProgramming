//presents cf

#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n; 
    vector<int>giftofrnd(n+1,0);
    for(int i=1;i<n+1;i++){
        cin>>giftofrnd[i];
    }
    vector<int>giftedto(n+1,0);
    for(int i=1;i<n+1;i++){
        giftedto[giftofrnd[i]]=i;
    }

    for(int i=1;i<n+1;i++){
        cout<<giftedto[i]<<" ";
    }
}
