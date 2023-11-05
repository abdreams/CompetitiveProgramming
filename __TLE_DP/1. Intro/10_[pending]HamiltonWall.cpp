//semper fi//https://codeforces.com/contest/1766/problem/C

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

vector<vector<int>>vis;

bool solve(int x,int y,vector<vector<char>>&wall){
    vis[x][y]=1;
    if((x==0 or x==1) and y==0){
        if(wall[x][y]=='B') return true;
        else return false;
    } 
    
    if(x<0 or y<0) return false; 
    
    if(wall[x][y]=='W') return false;

    bool take=false;

    if(wall[x][y]=='B' and !vis[x][y]){
        // vis[x][y]=1;
        take=(true and (solve(x+1,y,wall) or solve(x,y-1,wall) or solve(x-1,y,wall)));
    }
    return take;
}

int32_t main(){
ab_d();

    w(x){
        int m;
        cin>>m;
        vector<vector<char>>wall(2,vector<char>(m));
        vis.assign(2,vector<int>(m,0));

        for(int i=0;i<=1;i++){
            for(int j=0;j<m;j++){
                cin>>wall[i][j];
            }
        }
        cout<<(solve(0,m-1,wall) or solve(1,m-1,wall))<<endl;
        vis.clear();
    }

    return 0;
}
