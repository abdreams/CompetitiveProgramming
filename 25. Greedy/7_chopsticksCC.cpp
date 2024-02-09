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
    int n, d;
    cin >> n >> d;
    vector<int> arr(n, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int ans = 0;

    for (int i = 0; i < n - 1; i++) {  
        if(arr[i+1]-arr[i]<=d){
            ans++;
            i++;
        }
    }

    cout << ans << endl;

    return 0;
}
