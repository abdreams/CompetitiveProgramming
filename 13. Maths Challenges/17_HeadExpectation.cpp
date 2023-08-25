/*
Problem Name: Head Expectation
Problem Difficulty: 2
Problem Constraints: 
Problem Description:
What is the expected number of coin flips for getting N consecutive heads, given the value of N? 
Say N = 1, expected number of throws to get 1 head will be 2.

Input Format: An integer n 
Sample Input: 1
Output Format: An integer denoting the required answer
Sample Output: 2*/

#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n;
    
    cout<<pow(2,n+1)-2<<endl;

    return 0;
}

/*
Let the exepected number of coin flips be x. Based on previous exercises, we can wind up the whole case analysis in two basic parts

a) If we get 1st, 2nd, 3rd,...,n'th tail as the first tail in the experiment, then we have to start all over again.
b) Else we are done.

For the 1st flip as tail, the part of the equation is (1/2)(x+1)
For the 2nd flip as tail, the part of the equation is (1/4)(x+2)
...
For the k'th flip as tail, the part of the equation is (1/(2k))(x+k)
...
For the N'th flip as tail, the part of the equation is (1/(2N))(x+N)
The part of equation corrresponding to case (b) is (1/(2N))(N)

Adding,

x = (1/2)(x+1) + (1/4)(x+2) + ... + (1/(2^k))(x+k) + .. + (1/(2^N))(x+N) + (1/(2^N))(N)

Solving this equation is left as an exercise to the reader. The entire equation can be very easily reduced to the following form:

x = 2N+1-2

Thus, the expected number of coin flips for getting N consecutive heads is (2N+1 - 2).*/
