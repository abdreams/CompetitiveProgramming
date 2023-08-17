/*
Problem Name: XOR Profit Problem
Problem Difficulty: 2
Problem Constraints: l <= r <= 1000
Problem Description:
We are given two coins of value x and y. We have to find the maximum of value of a XOR b where x <= a <= b <= y.

Input Format: We are given two integers x and y
Sample Input: 5
6
Output Format: Print the maximum value of a XOR b
Sample Output: 3
*/

//CODEFORCES 276 D

#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    long long int a,b;
    cin>>a>>b;
    long long int xr = a^b;
    long long int msbpos=0;
    while(xr){
         msbpos++;
         xr = xr>>1;
    }

    cout<<(1LL<<msbpos)-1<<endl;

    return 0;
}
