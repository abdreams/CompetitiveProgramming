#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int             long long

char grid[15][15];
bool vis[15][15];
map<string,int> mapi;
map<string,int> mark;
int n, m;

void solve(int i, int j, string ans){
    if(i <= 0 || j <= 0 || i > m || j > m || vis[i][j]) return;
    vis[i][j] = 1;
    ans += grid[i][j];

    if(mapi[ans]){
        if(!mark[ans]){
            mark[ans] = 1;
            cout << ans << " ";
        }
    }

    for(int row = i - 1; row <= i + 1; row++){
        for(int col = j - 1; col <= j + 1; col++){
            solve(row, col, ans);
        }
    }

    ans.erase(ans.length() - 1);
    vis[i][j] = 0;
}

void ab_d(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        mapi[s] = 1;
    }

    cin >> m;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            memset(vis, 0, sizeof(vis));
            string ans = "";
            solve(i, j, ans);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ab_d();

    return 0;
}
