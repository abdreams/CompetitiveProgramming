/*Problem Name: Catalan Numbers
Problem Difficulty: None
Problem Constraints: 1 <= N <= 100
Problem Description:
Print nth [Catalan Number](https://en.wikipedia.org/wiki/Catalan_number).
The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14,.. .

https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

Input Format: One integer n
Sample Input: 10
Output Format: Print the catalan number at position N.
Sample Output: 16796
*/

#include<bits/stdc++.h>

#define int unsigned long long

using namespace std;

int dp[100005];

int catalan(int n)
{

    if (n==1 or n==0) return dp[n]= 1;
    
    if (dp[n]!=-1) return dp[n];
    int ans = 0;
    for (int i = 0; i < n; i++) ans += catalan(i) * catalan(n - i - 1);
 
    return dp[n]= ans;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < n; i++) cout << catalan(i) <<endl;
    return 0;
}
