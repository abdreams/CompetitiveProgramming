// o(n log log n)
//https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

#include<bits/stdc++.h>
#define int long long

using namespace std;

void prime_sieve(int n){
    vector<int>primes(n+1,0);

    for(int i=3;i<=n;i=i+2){
        primes[i]=1;
    }

    for(int i=3;i<=n;i=i+2){
        if(primes[i]==1){
        for(int j=i*i;j<=n;j+=i){
            primes[j]=0;
        }
        }
    }
    primes[2]=1;
    primes[1]=primes[0]=0;

    for(int i=0;i<=n;i++){
        if(primes[i]==1) cout<<i<<" ";
    }
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n; 

    prime_sieve(n);

    return 0;
}
