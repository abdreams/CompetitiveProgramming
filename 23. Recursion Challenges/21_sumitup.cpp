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

vector<vector<int>> ans;
vector<int> arr;
int n;

void solve(int ind, int target, vector<int> res){

    if(ind == n){
        if(target == 0) {
            ans.push_back(res);
        }
        return;
    }

    solve(ind + 1, target, res);


    if(target >= arr[ind]){
        res.push_back(arr[ind]);
        solve(ind + 1, target - arr[ind], res);
        res.pop_back(arr[ind]);
    }


}

int32_t main(){
    ab_d();
    cin >> n;
    arr.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());

    int target;
    cin >> target;
    vector<int> num;
    solve(0, target, num);

    set<vector<int>> unique_combinations(ans.begin(), ans.end());
    for(auto it : unique_combinations){
        for(auto i : it){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
