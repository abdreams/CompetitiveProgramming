#include <bits/stdc++.h>
using namespace std;

#define int long long

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int32_t main(){
ab_d();
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<pair<int,string>>teams(n);
        for (int i = 0; i < n; i++)
        {
            int a;
            string b;
            cin>>b>>a;
            teams[i].first=a;
            teams[i].second=b;
        }
        sort(teams.begin(),teams.end());
        int badness=0;
        for (int i = 0; i < n; i++)
        {
            badness+=abs(teams[i].first-(i+1));
        }
        
        cout<<badness<<endl;
    }
    
    return 0;
}
