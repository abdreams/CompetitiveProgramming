//https://codeforces.com/problemset/problem/26/A

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
    
    int ans=0;

    for(int j=3;j<=n;j++){
        set<int>st;
            for(int i=0;primes[i]<=j;i++){
                if(j%primes[i]==0)
                    st.insert(i);
            }
       if(st.size()==2) ans++;
    }

    cout<<ans<<endl;

    return 0;
}
