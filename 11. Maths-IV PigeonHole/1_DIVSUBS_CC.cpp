// https://www.codechef.com/problems/DIVSUBS

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){

    int n;
    cin>>n;
    vector<int>arr;
    vector<pair<int, pair<int, int> >>pre(n);
    map<int,int>pre;
    for(int i=0;i<n;i++){
        pre[i].first=0;
    }
    int sum=0;
    pre[0].first=1;
    int ind=-1;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%n==0){
            cout<<1<<endl;
            cout<<i+1<<endl;
            return;
        }
        arr.push_back(x);
        sum+=x;
        sum%=n;
        sum=(sum+n)%n;
        pre[sum].first++;
        if(pre[sum].first==1) pre[sum].second.first=i;
        if(pre[sum].first>1) {
            pre[sum].second.second=i;
        }
    }

    int count=0;
    for(int i=0;i<n;i++){
        if(pre[sum].first==0 or pre[sum].first==1) count++;
    }
    if(count==n) cout<<-1<<endl;
    
    cout<<pre[sum].second.second-pre[sum].second.first<<endl;

    for(int i=pre[sum].second.first+1;i<=pre[sum].second.second;i++){
        cout<<i<<" ";
    }
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--){
         solve();
    }

    return 0;
}
