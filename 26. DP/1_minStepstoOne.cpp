// https://www.codingninjas.com/studio/problems/min-steps-to-one-using-dp_920548?leftPanelTabValue=SOLUTION

#include <bits/stdc++.h>
// vector<int>dp;
// memo::
// int solve(int n){
// 	if(n<=0) return INT_MAX;
// 	if(n==1) return 0;

// 	if(dp[n]!=-1) return dp[n];

// 	int steps_one=1+solve(n-1);
// 	int steps_two=INT_MAX;
// 	int steps_three=INT_MAX;
// 	if(n%2==0)
// 		steps_two=1+solve(n/2);
// 	if(n%3==0)
// 		steps_three=1+solve(n/3);
	
// 	return dp[n]= min(steps_one,min(steps_two,steps_three));
	

// }

int countStepsToOne(int n) {
	
	vector<int>dp(n+1,0);
	dp[0]=0;
	dp[1]=0;
	for(int i=2;i<=n;i++){
		if(i%2==0 and i%3==0)
			dp[i]=min(dp[i-1]+1,min(dp[i/2]+1,dp[i/3]+1));
		else if(i%2==0)
			dp[i]=min(dp[i-1]+1,dp[i/2]+1);
		else if(i%3==0)
			dp[i]=min(dp[i-1]+1,dp[i/3]+1);	
		else 
			dp[i]=1+dp[i-1];				
	}
	return dp[n];
	

}