/*
https://hack.codingblocks.com/app/practice/1/222/problem

Problem Name: Deepak and Primes
Problem Difficulty: None
Problem Constraints: 1<=n<=500000
Problem Description:
Deepak is learning Sieve of Eratosthenes, He is stuck somewhere. Help him printing prime numbers.

Input Format: Single line containing integral value n.
Sample Input: 1
Output Format: Integral value denoting nth prime number.
Sample Output: 2
*/

#include<bits/stdc++.h>
#include<bitset>
#define int long long

using namespace std;
int n=10000000;
bitset<10000005>b; // stores a bit indicating 1 or 0 at each index
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

    int n;
    cin>>n;

    cout<<primes[n-1]<<endl;

    return 0;
}
