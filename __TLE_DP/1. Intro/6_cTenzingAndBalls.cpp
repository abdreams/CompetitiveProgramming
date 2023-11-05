//semper fi//
//https://codeforces.com/problemset/problem/1842/C

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

int solve(int ind,int cur_color,vector<int>&colors){
    if(ind==-1) return 0;

    if(cur_color==-1){
        cur_color=color[ind];
    } 
    if(color[ind]!=cur_color){
        return solve(ind+1,cur_color,colors);
    }
    if(color[ind]==cur_color){
        
    }

}   

int32_t main(){
ab_d();

    w(x){
        int n;
        cin>>n;
        vector<int>colors(n);
        for(int i=0;i<n;i++) 
            cin>>colors[i];

    }

    return 0;
}
