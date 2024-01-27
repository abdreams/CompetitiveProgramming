#include <bits/stdc++.h>
using namespace std;

#define int long long

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

bool psbl(vector<int>&arr,int maxpg_assumed, int m){
    bool res=false;
    int s=0;
    m--;
    for (int i = 0; i < arr.size() ; i++)
    {
        s+=arr[i];
        if(s>maxpg_assumed){
            s=arr[i];
            m--;
        }
    }
    
    if(m>=0) res=true; // why do we not talk about exhausting m?!

    return res;
}

int32_t main(){
ab_d();
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>arr(n,0);
        int sm=0;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            sm+=arr[i];
        }

        int s=arr[n-1];
        int e=sm;
        int ans=INT_MAX;
        while (s<=e)
        {
            int mid=s+(e-s)/2;
            if(psbl(arr,mid,m)){
                ans=min(ans,mid);
                e=mid-1;
            }
            else s=mid+1;
        }
        
        cout<<ans<<endl;
        
    }
    

    return 0;
}
