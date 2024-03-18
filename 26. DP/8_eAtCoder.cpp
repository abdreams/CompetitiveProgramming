#include <bits/stdc++.h>
using namespace std;

int dp[100+1][100000+1];

int mini(int ind,int val,vector<pair<int,int>>&v){
    if(val<=0){return 0;}
    if(ind<0){return 1e9+1;}
    if(dp[ind][val]!=-1){return dp[ind][val];}
    dp[ind][val]=min(mini(ind-1,val-v[ind].second,v)+v[ind].first,
        mini(ind-1,val,v));
    return dp[ind][val];
}


int main(){
    memset(dp,-1,sizeof(dp));
    int n,w;
    cin>>n>>w;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    for(int i=1e5;i>=1;i--){
        if(mini(v.size()-1,i,v)<=w){
            cout<<i<<endl;
            break;
        }
    }
}