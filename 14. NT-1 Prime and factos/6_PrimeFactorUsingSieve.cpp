#include<bits/stdc++.h>
#include<bitset>
#define int long long

using namespace std;
int n=10000000;
bitset<10000005>b; // stores a bit indicating 1 or 0 at each index
vector<int>primes;
vector<int>factors;

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

void prime_factorization(int n){
    for(int i=0;primes[i]*primes[i]<=n;i++){
      
        while(n%primes[i]==0) {
            factors.push_back(primes[i]);
            n=n/primes[i];
        }
        
    }
    if (n > 1) {
        factors.push_back(n); // If n is prime or has a prime factor > sqrt(n)
    }
    
    for(auto it:factors) cout<<it<<" ";
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    sieve();
    int n;
    cin>>n;

    prime_factorization(n);

    return 0;
}
