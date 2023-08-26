//Large prime number check for prime or not using seive 
// for nos greater than 10^7 as seive max utne size ki hi hai
//2147483647 is prime

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

}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    sieve();
    int n;
    cin>>n;
    int flag=1;

    if(n<=10000000){
        if(b[n]) cout<<"Prime!";
        else cout<<"Non Prime!";
    }

    else {
        for(int i=0;primes[i]*primes[i]<=n;i++){

            if(n%primes[i]==0) flag=0;
            break;
        }

        if(flag){
            cout<<"Prime!";
        }
        else cout<<"Non Prime!";
    }


    return 0;
}
