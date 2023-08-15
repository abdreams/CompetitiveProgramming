/*
Problem Name: Unique Numbers - II
Problem Difficulty: None
Problem Constraints: n < 10^5
Problem Description:
We are given an array containg n numbers. All the numbers are present twice except for 
two numbers which are present only once. 
Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )

Input Format: First line contains the number n. Second line contains n space separated number.
Sample Input: 4
3 1 2 1
Output Format: Output a single line containing the unique numbers separated by space
Sample Output: 2 3
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n; //no of elements in array
    vector<int>arr;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    return 0;
}
