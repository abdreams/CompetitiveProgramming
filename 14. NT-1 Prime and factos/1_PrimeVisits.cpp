// https://hack.codingblocks.com/app/practice/1/1039/problem

#include<bits/stdc++.h>
#define int long long

using namespace std;

void prime_sieve(int a, int n){
    int count=0;
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

    for(int i=a;i<=n;i++){
        if(primes[i]==1) count++;
    }
    cout<<count<<endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--){
    int a,b;
    cin>>a>>b; 

    prime_sieve(a,b);
    }

    return 0;
}
