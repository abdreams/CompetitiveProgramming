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
