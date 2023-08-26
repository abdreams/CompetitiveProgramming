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
    int n;
    cin>>n;

    primefactor(n);

    int ans=1;
    for(auto it:factors){
        ans*=(it.second+1)
    }
    cout<<ans<<endl;

    return 0;
}
