// semper fi //
// abdreams //
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define w(x)            int x; cin>>x; while(x--)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int solve(int l,int r,int num_to_find,vector<int>&arr){
    if(l<=r){
        int mid=l+(r-l)/2;

        if(arr[mid]==num_to_find) return mid;
        if(arr[mid]>num_to_find) return solve(l,mid-1,num_to_find,arr);
        else return solve(mid+1,r,num_to_find,arr);
    }
    return -1;
}

int32_t main(){
ab_d();
    int n;
    cin>>n;

    int num_to_find;
    cin>>num_to_find;

    vector<int>arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<solve(0,n-1,num_to_find,arr);

    return 0;
}
