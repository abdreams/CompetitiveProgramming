#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
map<int, int>last;

bool compare(int a,int b)
{
    return last[a]<last[b];
}

int32_t main(){
ab_d();
    int n;
    cin>>n;
    vector<int>v;
    vector<int>a(n,0);
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
        if(last.find(a[i])==last.end())
            v.pb(a[i]);
        last[a[i]]=i;
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}
