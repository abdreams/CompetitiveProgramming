/*
Problem Name: Choosing Numbers
Problem Difficulty: None
Problem Constraints: 
Problem Description:
N students are asked to choose a number from 1 to 100 inclusive.
What is the expected number of students that would choose a single digit number? 

Input Format: An integer n denoting number of students
Sample Input: 8
Output Format: A float denoting the answer upto 2 decimal point accuracy
Sample Output: 0.72
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
    int n;
    cin >> n;

    float x = n * 0.09;

    cout << fixed << setprecision(2) << x;

    return 0;
}

