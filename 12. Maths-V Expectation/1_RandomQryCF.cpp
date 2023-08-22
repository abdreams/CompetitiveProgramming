//https://codeforces.com/problemset/problem/846/F

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[1000006] = {0};
ll last_occured[1000006] = {0};
ll dp[1000006] = {0};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ll n; 
    cin >> n;

    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(last_occured,0,sizeof(last_occured));
    memset(dp,0,sizeof(dp));

    dp[0] = 0;
    double sum = 0.0;

    for(ll i = 1; i <= n; i++) {    

        dp[i] = dp[i-1] + (i - last_occured[a[i]]);
        last_occured[a[i]] = i;

        sum += dp[i];

    }

    double result = 0.0;
    result = (2*(sum - n) + n)/(n*n*1.0);

    cout << fixed << setprecision(6) << result << endl;


return 0;
}