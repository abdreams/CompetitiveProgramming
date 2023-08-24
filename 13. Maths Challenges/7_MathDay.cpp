/*
Problem Name: Math Day
https://hack.codingblocks.com/app/practice/3/139/problem

Problem Difficulty: None
Problem Constraints: 1 ≤ T ≤ 100
1 ≤ A ≤ 10^5.
1 ≤ N ≤ 10^5.
1 ≤ P ≤ 10^5.
Problem Description:
Math Day is being celebrated at Coding Blocks. So Prateek Bhaiya rolled out a contest on Maths Problems. Here goes one.<br/> Given three positive integers <b>A,N,P</b>. Compute <b>A<sup>N!</sup> %P</b>.<br/><br/>


Input Format: The first line of the input gives the number of test cases, <b>T</b>. <b>T</b> lines follow.
<br/> Each line contains three integers <b>A, N</b> and <b>P</b>, as described above.
Sample Input: 2
2 1 2
3 3 2
Output Format: For every test case, print the answer in a new line.
Sample Output: 0
1*/

#include<bits/stdc++.h>
#define int long long
using namespace std;


int fastexpo(int a, int n, int p){
	
	 int ans = 1;
	 
	 while(n > 0){
		
		if(n & 1){
			ans = ((ans % p) * (a % p)) % p;
		}

		a = ((a % p) * (a % p)) % p;
		n = n >> 1;
	 }
	return ans;
}
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

	int t;
	cin>>t;
	while(t--){
		int a, n, p;
		cin>>a>>n>>p;
		while(n > 0){
			a = fastexpo(a, n, p);
			n--;
		}

        cout<<a<<endl;
	}
	return 0;
}