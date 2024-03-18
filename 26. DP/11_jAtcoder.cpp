#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

ld dp[301][301][301];

ld func(int zero, int one, int two, int three,int n){
    if(one+two+three==0) return 0;

    if(dp[one][two][three]!=-1) return dp[one][two][three];
    
    ld ans = n; 
    
    if(one) 
        ans+=(one*func(zero+1,one-1,two,three,n));
    
    if(two) 
        ans+=(two*func(zero,one+1,two-1,three,n));
    
    if(three) 
        ans+=(three*func(zero,one,two+1,three-1,n));
    
    ans/=(ld)(n-zero);
    
    return dp[one][two][three] = ans;
}

int32_t main()
{
ab_d();

    int n;
    cin>>n;
    vector<int> prob(n);
    vector<int> count(4,0);
    
    for(int i = 0; i < n; i++){
        cin>>prob[i];
        count[prob[i]]++;
    }
    for(int i = 0; i < 301; i++){
        for(int j = 0; j < 301; j++){
            for(int k = 0; k < 301; k++){
                dp[i][j][k] = -1.00;
            }
        }
    }

    cout<< setprecision(10) << fixed << func(count[0],count[1],count[2],count[3],n)<<endl;
    
    return 0;
}