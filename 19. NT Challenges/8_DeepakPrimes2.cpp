/*
https://hack.codingblocks.com/app/practice/1/388/problem

Problem Name: Deepak and Primes II
Problem Difficulty: 
Problem Constraints: 1<=T<=10
1<=m<=n<=1000000000, n-m<=100000
Problem Description:
After learning sieve of Eratosthenes, Deepak wants to play more with the primes. This time he is trying to print primes between two integers. Help him in this task.

Input Format: First line contains a single integer 'T' denoting number of test cases. Then 'T' lines follow each containing two integers 'm'  and 'n'. 
Sample Input: 2
5 10
11 20
Output Format: Print the prime numbers from 'm' till 'n' (both inclusive), one number per line and each test case is separated by an empty line.
Sample Output: 
5
7

11
13
17
19
*/

//https://www.spoj.com/problems/PRIME1/cstart=10

#include<bits/stdc++.h>
#include<bitset>
#define int long long

using namespace std;
int n=100000;
bitset<100005>b; // stores a bit indicating 1 or 0 at each index
vector<int>primes;

void sieve(){

    for(int i=3;i<=n;i=i+2){
        b[i]=1;
    }

    for(int i=3;i<=n;i=i+2){
        if(b[i]==1){
        for(int j=i*i;j<=n;j+=i){
            b[j]=0;
        }
        }
    }
    b[2]=1;
    b[1]=b[0]=0;

    for(int i=0;i<=n;i++){
        if(b[i]==1) primes.push_back(i);
    }

    // for(auto it:primes) cout<<it<<" ";

}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    sieve();
    int t;
    cin>>t;
    while(t--){
    int a,b;
    cin>>a>>b;

    vector<int>segment(b-a+1,0);

    for(auto x:primes){
        if(x*x>b) break;

        int start=(a/x)*x;

        if(x>=a and x<=b){
            start=x*2;
        }

       for(int i=start;i<=b;i+=x){
        if(i<a) 
            continue;
        segment[i-a]=1;
       } 
    }
    for(int i=a;i<=b;i++){
        if(segment[i-a]==0 and i!=1) cout<<i<<endl;
    }
    cout<<endl;
    }

    return 0;
}
