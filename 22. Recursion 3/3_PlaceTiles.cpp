#include<bits/stdc++.h>

using namespace std;

int solve(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;  

    int take_1x4=0;
    int take_4x1=0;

    if (n >= 1) take_4x1 = solve(n - 1);
    
    if (n >= 4) take_1x4 = solve(n - 4);

    return take_1x4 + take_4x1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int n,m;
    cin >> n;

    int ans = solve(n);
    cout << ans << endl; 

    return 0;
}
