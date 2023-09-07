/*
https://hack.codingblocks.com/app/practice/1/297/problem

Problem Name: T-Prime
Problem Difficulty: None
Problem Constraints: n <= 10^5
xi <= 10^12
Problem Description:
We know that prime numbers are positive integers that have exactly two distinct positive divisors. Similarly, we'll call a positive integer t Т-prime, if t has exactly three distinct positive divisors.

You are given an array of n positive integers. For each of them determine whether it is Т-prime or not.

Input Format: First Line : n , Number of elements in an array
Second Line : xi ( i from 1 to n)    
Sample Input: 3
4 5 6
Output Format: YES if its T-Prime
NO if its not a T-Prime
Sample Output: YES
NO
NO
*/

#include<bits/stdc++.h>
#include<bitset>
#define int long long

using namespace std;
int n=10000000;
bitset<10000005>b; // stores a bit indicating 1 or 0 at each index
vector<int>primes;
vector<pair<int,int>>factors;

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

void primefactor(int n){
    for(int i=0;(primes[i]*primes[i])<=n;i++){
        int prime = primes[i];
        if(n%prime==0){
            int count = 0;
            while(n%prime==0){
                count++;
                n=n/prime;
            }
            factors.push_back({prime,count});
        }
    }
    if(n>1) factors.push_back({n,1});

    // for(auto it : factors){
    //     cout<< it.first << " ^ " << it.second<<endl;
    // }
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
    primes.clear();
    factors.clear();
    int n;
    cin>>n;
    primefactor(n);

    int ans=1;
    for(auto it:factors){
        ans*=(it.second+1);
    }
    // cout<<ans<<endl;
    if(ans==3) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    }

    return 0;
}
