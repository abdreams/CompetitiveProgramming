//https://www.spoj.com/problems/FAVDICE/
/*BuggyD loves to carry his favorite die around. Perhaps you wonder why it's his favorite? Well, his die is magical and can be transformed into an N-sided unbiased die with the push of a button. Now BuggyD wants to learn more about his die, so he raises a question:

What is the expected number of throws of his die while it has N sides so that each number is rolled at least once?
USE COUPON COLLECTOR SERIES
WE USE IT WHENEVER WE WANT N DISTINCT (ALL PSBL DISTINCT ITEMS) FROM A SET OF VALUES
n*(1+1/2+1/3+1/4+...+1/n)
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

	int t;
	cin>>t; 
	while(t--)
	{
		double n,res;
		cin>>n;
		res=0;
		double temp=n;
		while(n>=1)
		{   
			res+=double(temp/n);
			n--;
		}
		printf("%.2lf\n",res);
	}
	return 0;
}