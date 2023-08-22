/*Problem Name: Power(O(logn))
https://hack.codingblocks.com/app/practice/1/16/problem
Problem Difficulty: None
Problem Constraints: None
Problem Description:
Take as input x and n, two numbers. Write a function to calculate x raise to power n. Target complexity is O(logn).
NOTE: Try both recursive and bitmasking approach.

Input Format: Enter the number N and its power P
Sample Input: 2
3
Output Format: Display N^P
Sample Output: 8
*/

#include<bits/stdc++.h>

using namespace std;

double faspow(double n,int p){
    if(p==1) return n;

    if(p%2==1) return n*faspow(n,p/2)*faspow(n,p/2);
    return faspow(n,p/2)*faspow(n,p/2);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    double n;
    int p;
    cin>>n>>p; 

    if(p<0){
        p=abs(p);
        n=1/n;
    }

    cout<<faspow(n,p)<<endl;

}
