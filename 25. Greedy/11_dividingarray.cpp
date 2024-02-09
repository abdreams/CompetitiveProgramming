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

int32_t main(){
ab_d();
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n,0);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int mini = 0 ;
        for(int i = 0 ; i < n ; i+=2){
            mini+=(arr[i+1]-arr[i]);
        }
        int maxi = 0 ;
        for(int i = n-1 ; i>=0 ; i--){
            if(i>=(n/2)) maxi+=arr[i];
            else maxi-=arr[i];
        }
        cout<<mini<<" "<<maxi<<endl;
    }
    

    return 0;
}
