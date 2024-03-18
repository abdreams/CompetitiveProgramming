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

int solve(int k , vector<int>&arr , int turn , vector<vector<int>>&dp)
{
	if(k == 0)
		return 0;

	if(dp[k][turn] != -1)
		return dp[k][turn];

	int ans = 0;
	for(int i = 0 ; i<arr.size() ; i++)
	{
		if(arr[i] <= k)
		{
			ans = ans or !solve(k - arr[i] , arr , !turn , dp);
		}
	}

	return dp[k][turn] = ans;
}

int32_t main()
{
ab_d();

    int n , k;
    cin>>n>>k;
    vector<int>arr(n,0);

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    vector<vector<int>>dp(k+1 , vector<int>(2 , -1));

    int turn = 0;

    int ans = solve(k , arr , 0 , dp);
    if(ans == 1)
    {
        cout<<"First"<<endl;
    } 
    else
        cout<<"Second"<<endl;

    return 0; 
}