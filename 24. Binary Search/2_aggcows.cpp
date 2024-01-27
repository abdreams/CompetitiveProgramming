#include <bits/stdc++.h>
using namespace std;

#define int long long
//https://leetcode.com/discuss/general-discussion/1302335/aggressive-cows-spoj-fully-explained-c
void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

bool psbl(vector<int> stalls, int minDist, int k)
{
    int cows=1;
    int lastCowPosition=stalls[0];
    for(int i=1;i<stalls.size();i++)
    {
        if(stalls[i]-lastCowPosition>=minDist)
        {
            cows++;
            lastCowPosition=stalls[i];
            if(cows>=k) return true;
        }
    }
    return false;
}

int32_t main(){
ab_d();
    int t;
    cin>>t;
    while (t--)
    {
        int n,c;
        cin>>n>>c;
        vector<int>arr(n,0);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int low=1;
        int high=arr[n-1]-arr[0];
        int ans;
        while(low<=high){
            int mid=(low)+(high-low)/2;
            if(psbl(arr,mid,c)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        cout<< ans<<endl;
    }
    return 0;
}
