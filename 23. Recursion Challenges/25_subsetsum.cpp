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

bool solve(int ind, vector<int>& arr, int n, int sum, int cl){
    if(ind == n){
        if(sum == 0 && cl == 0) return false;
        else if(sum == 0) return true;
        else return false;
    }
    
    if(sum == 0 && cl != 0){
        return true;
    }
    
    bool take = solve(ind + 1, arr, n, sum + arr[ind], cl + 1);
    bool nott = solve(ind + 1, arr, n, sum, cl);
    return take or nott;
}

int32_t main(){
    ab_d();
    w(t){
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        bool ans = solve(0, arr, n, 0, 0);
        if(ans){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}
